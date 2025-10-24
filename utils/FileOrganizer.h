//
// Created by fsh33 on 10/24/2025.
//

#ifndef CLOUDSHELF_FILEORGANIZER_H
#define CLOUDSHELF_FILEORGANIZER_H
#include <sqlite3.h>
#include <string>
#include <vector>
using namespace std;
struct FileRecord {
    long long fileId;
    string name;
    string path;
    string extension;
    string writeTime;
    int size;
    string baseFolderName;
};

class FileOrganizer {
public:
    FileOrganizer(sqlite3* database, string destPath);

    // Main function to organize files by time
    void organizeFilesByTime(bool newestFirst = true,string sourcePath="");

    // Organize files older than a specific date
    void organizeOldFiles(const string& cutoffDate);

    // Organize files newer than a specific date
    void organizeNewFiles(const string& cutoffDate);

private:
    sqlite3* DB;
    string destinationBasePath;
    vector<FileRecord> queryAndSortFiles(bool newestFirst);
    vector<FileRecord> queryFilesOlderThan(const string& cutoffDate);
    vector<FileRecord> queryFilesNewerThan(const string& cutoffDate);
};
#endif //CLOUDSHELF_FILEORGANIZER_H