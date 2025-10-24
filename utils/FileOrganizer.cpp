#include <iostream>
#include  "./FileOrganizer.h"
#include <vector>
#include <string>
#include "./MoveAndOrg.h"
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
FileOrganizer::FileOrganizer(sqlite3* database, string destPath) {
    DB = database;
    destinationBasePath = destPath;
}

// Query and sort all files
vector<FileRecord> FileOrganizer::queryAndSortFiles(bool newestFirst) {
    vector<FileRecord> records;
    sqlite3_stmt* stmt;
    
    const char* sql;
    if (newestFirst) {
        sql = "SELECT File.ID, File.Name, File.Path, Data.Extension, Data.WriteTime, Data.Size, Data.BaseFolderName "
              "FROM File "
              "JOIN Data ON File.ID = Data.FileID "
              "ORDER BY Data.WriteTime DESC";  // Newest first
    } else {
        sql = "SELECT File.ID, File.Name, File.Path, Data.Extension, Data.WriteTime, Data.Size, Data.BaseFolderName "
              "FROM File "
              "JOIN Data ON File.ID = Data.FileID "
              "ORDER BY Data.WriteTime ASC";   // Oldest first
    }
    
    int rc = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(DB));
        return records;
    }
    
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        FileRecord record;
        record.fileId = sqlite3_column_int64(stmt, 0);
        record.name = (const char*)sqlite3_column_text(stmt, 1);
        record.path = (const char*)sqlite3_column_text(stmt, 2);
        record.extension = (const char*)sqlite3_column_text(stmt, 3);
        record.writeTime = (const char*)sqlite3_column_text(stmt, 4);
        record.size = sqlite3_column_int(stmt, 5);
        record.baseFolderName = (const char*)sqlite3_column_text(stmt, 6);
        
        records.push_back(record);
    }
    
    sqlite3_finalize(stmt);
    return records;
}

// Query files older than cutoff date
vector<FileRecord> FileOrganizer::queryFilesOlderThan(const string& cutoffDate) {
    vector<FileRecord> records;
    sqlite3_stmt* stmt;
    
    const char* sql = "SELECT File.ID, File.Name, File.Path, Data.Extension, Data.WriteTime, Data.Size, Data.BaseFolderName "
                      "FROM File "
                      "JOIN Data ON File.ID = Data.FileID "
                      "WHERE Data.WriteTime < ? "
                      "ORDER BY Data.WriteTime ASC";
    
    int rc = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(DB));
        return records;
    }
    
    sqlite3_bind_text(stmt, 1, cutoffDate.c_str(), -1, SQLITE_TRANSIENT);
    
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        FileRecord record;
        record.fileId = sqlite3_column_int64(stmt, 0);
        record.name = (const char*)sqlite3_column_text(stmt, 1);
        record.path = (const char*)sqlite3_column_text(stmt, 2);
        record.extension = (const char*)sqlite3_column_text(stmt, 3);
        record.writeTime = (const char*)sqlite3_column_text(stmt, 4);
        record.size = sqlite3_column_int(stmt, 5);
        record.baseFolderName = (const char*)sqlite3_column_text(stmt, 6);
        
        records.push_back(record);
    }
    
    sqlite3_finalize(stmt);
    return records;
}

// Query files newer than cutoff date
vector<FileRecord> FileOrganizer::queryFilesNewerThan(const string& cutoffDate) {
    vector<FileRecord> records;
    sqlite3_stmt* stmt;
    
    const char* sql = "SELECT File.ID, File.Name, File.Path, Data.Extension, Data.WriteTime, Data.Size, Data.BaseFolderName "
                      "FROM File "
                      "JOIN Data ON File.ID = Data.FileID "
                      "WHERE Data.WriteTime > ? "
                      "ORDER BY Data.WriteTime DESC";
    
    int rc = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(DB));
        return records;
    }
    
    sqlite3_bind_text(stmt, 1, cutoffDate.c_str(), -1, SQLITE_TRANSIENT);
    
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        FileRecord record;
        record.fileId = sqlite3_column_int64(stmt, 0);
        record.name = (const char*)sqlite3_column_text(stmt, 1);
        record.path = (const char*)sqlite3_column_text(stmt, 2);
        record.extension = (const char*)sqlite3_column_text(stmt, 3);
        record.writeTime = (const char*)sqlite3_column_text(stmt, 4);
        record.size = sqlite3_column_int(stmt, 5);
        record.baseFolderName = (const char*)sqlite3_column_text(stmt, 6);
        
        records.push_back(record);
    }
    
    sqlite3_finalize(stmt);
    return records;
}

void FileOrganizer::organizeFilesByTime(bool newestFirst,string sourcePath) {
    cout << "\n=== Starting File Organization ===" << endl;
    cout << "Sorting order: " << (newestFirst ? "Newest First" : "Oldest First") << endl;

    vector<FileRecord> sortedFiles = queryAndSortFiles(newestFirst);

    if (sortedFiles.empty()) {
        cout << "No files found in database." << endl;
        return;
    }

    cout << "Found " << sortedFiles.size() << " files to organize." << endl;

    string today = "2025-10-24 00:00:00";
    string weekAgo = "2025-10-17 00:00:00";
    string monthAgo = "2025-09-24 00:00:00";

    int recentCount = 0, thisWeekCount = 0, thisMonthCount = 0, archiveCount = 0;

    for (const auto& file : sortedFiles) {
        string categoryFolder;

        // Categorize by write time
        if (file.writeTime >= today) {
            categoryFolder = "Recent";
            recentCount++;
        }
        else if (file.writeTime >= weekAgo) {
            categoryFolder = "ThisWeek";
            thisWeekCount++;
        }
        else if (file.writeTime >= monthAgo) {
            categoryFolder = "ThisMonth";
            thisMonthCount++;
        }
        else {
            categoryFolder = "Archive";
            archiveCount++;
        }

        // Build destination using filesystem::path
        fs::path destinationFolder = fs::path(destinationBasePath) / categoryFolder;

        cout << "Moving: " << file.name << " (Created: " << file.writeTime
             << ") -> " << destinationFolder.string() << endl;
        // Build the CORRECT source path using baseFolderName from database
        fs::path correctSourcePath = fs::path(file.path).parent_path() / sourcePath/ file.name;
        cout << " Source path: " << correctSourcePath.string() << endl;
        // Create Operations object
        Operations moveOp(correctSourcePath.string(), destinationFolder.string());

        // DON'T pass baseFolderName - just pass empty string or the filename directly
        moveOp.copyAndRemoveFile(file.name, "");  // Empty string = no subfolder
    }

    cout << "\n=== Organization Complete ===" << endl;
    cout << "Recent (Today): " << recentCount << " files" << endl;
    cout << "This Week: " << thisWeekCount << " files" << endl;
    cout << "This Month: " << thisMonthCount << " files" << endl;
    cout << "Archive (Older): " << archiveCount << " files" << endl;
}
// Organize files older than a specific date
void FileOrganizer::organizeOldFiles(const string& cutoffDate) {
    cout << "\n=== Organizing Old Files ===" << endl;
    cout << "Moving files older than: " << cutoffDate << endl;
    
    vector<FileRecord> oldFiles = queryFilesOlderThan(cutoffDate);
    
    if (oldFiles.empty()) {
        cout << "No old files found." << endl;
        return;
    }
    
    cout << "Found " << oldFiles.size() << " old files." << endl;
    
    for (const auto& file : oldFiles) {
        cout << "\nArchiving: " << file.name << " (Created: " << file.writeTime << ")" << endl;
        
        Operations moveOp(file.path, destinationBasePath + "/Archive");
        moveOp.copyAndRemoveFile(file.name, file.baseFolderName);
    }
    
    cout << "\n=== Old Files Archived ===" << endl;
}

// Organize files newer than a specific date
void FileOrganizer::organizeNewFiles(const string& cutoffDate) {
    cout << "\n=== Organizing Recent Files ===" << endl;
    cout << "Moving files newer than: " << cutoffDate << endl;
    
    vector<FileRecord> newFiles = queryFilesNewerThan(cutoffDate);
    
    if (newFiles.empty()) {
        cout << "No recent files found." << endl;
        return;
    }
    
    cout << "Found " << newFiles.size() << " recent files." << endl;
    
    for (const auto& file : newFiles) {
        cout << "\nMoving: " << file.name << " (Created: " << file.writeTime << ")" << endl;
        
        Operations moveOp(file.path, destinationBasePath + "/Recent");
        moveOp.copyAndRemoveFile(file.name, file.baseFolderName);
    }
    
    cout << "\n=== Recent Files Organized ===" << endl;
}