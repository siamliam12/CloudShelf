//
// Created by fsh33 on 10/16/2025.
//

#include "dbConnection.h"
#include <iostream>
#include <sqlite3.h>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

sqlite3* InitializeDatabase(string dbFilePath) {
    sqlite3* DB = nullptr;
    int rc;

    fs::path db_path(dbFilePath);
    if (db_path.has_parent_path()) {
        std::error_code ec;
        fs::create_directories(db_path.parent_path(), ec);
    }
    // 1. Open or create the database file
    // sqlite3_open() automatically creates the file if it doesn't exist.
    rc = sqlite3_open(dbFilePath.c_str(), &DB);
    if (rc != SQLITE_OK) {
        // Handle failed open
        std::cerr << "Cannot open database: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_close(DB); // Must clean up the partial handle if opening failed
        return nullptr;
    }
    std::cout << "Database opened successfully." << std::endl;

    // 2. Define the schema (CREATE TABLE statements)
    const char* sqlSchema =
    "CREATE TABLE IF NOT EXISTS File("
     "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
     "Name TEXT NOT NULL,"
     "Path TEXT"
     ");" // <-- Note: No comma here, just close parenthesis and semicolon

    "CREATE TABLE IF NOT EXISTS Data("
     "FileID INTEGER,"
     "Extension REAL,"
     "WriteTime DATETIME,"
     "Size INTEGER,"
     "BaseFolderName TEXT,"
     "FOREIGN KEY(FileID) REFERENCES File(ID)"
     ");" // <-- Note: No comma here, just close parenthesis and semicolon

    "CREATE TABLE IF NOT EXISTS Perm("
     "FileID INTEGER,"
     "Owner TEXT,"
     // Check if there is an invisible character or extra space/newline here that breaks the string literal concatenation.
     "Groups TEXT,"
     "Others TEXT,"
     "FOREIGN KEY(FileID) REFERENCES File(ID)" // If this is the last item, no comma is needed before the final closing parenthesis.
     ");" // <-- Statement termination.
;

    // 3. Execute the schema creation SQL using sqlite3_exec
    char* zErrMsg = 0;
    rc = sqlite3_exec(DB, sqlSchema, 0, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        // Handle failed execution (DDL error)
        std::cerr << "SQL error during schema creation: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        sqlite3_close(DB); // Close connection on initialization failure
        return nullptr;
    }
    std::cout << "Schema created successfully." << std::endl;
    // 4. Return the active database connection pointer
    return DB;
}
void CloseDatabase(sqlite3* DB) {
    if (DB) {
        // sqlite3_close() is the destructor for the database connection object [3, 6]
        sqlite3_close(DB);
        // Always closing the connection is important to prevent memory leaks [9, 10]
        std::cout << "Database connection closed." << std::endl;
    }
}

// Function definition
long long insert_file_record(sqlite3* DB, string name, string path) {
    sqlite3_stmt* stmt = NULL;
    int rc;
    long long new_file_id = -1;

    // SQL statement for File table [3, 6]
    const char* sql = "INSERT INTO File (Name, Path) VALUES (?, ?)";

    // 1. Prepare the statement
    rc = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "File statement preparation failed: %s\n", sqlite3_errmsg(DB));
        return -1;
    }

    // 2. Bind parameters (1-indexed)

    // Bind Name (TEXT) to parameter 1
    rc = sqlite3_bind_text(stmt, 1, name.c_str(), (int)name.length(), SQLITE_TRANSIENT);

    // Bind Path (TEXT) to parameter 2
    if (rc == SQLITE_OK) {
        rc = sqlite3_bind_text(stmt, 2, path.c_str(), (int)path.length(), SQLITE_TRANSIENT);
    }

    if (rc != SQLITE_OK) {
        fprintf(stderr, "File binding failed for %s: %s\n", name.c_str(), sqlite3_errmsg(DB));
        sqlite3_finalize(stmt);
        return -1;
    }

    // 3. Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "File insertion failed for %s: %s\n", name.c_str(), sqlite3_errmsg(DB));
        // Note: SQLITE_CONSTRAINT may be returned if Path is not UNIQUE [3, 6]
    } else {
        // Successful execution
        new_file_id = sqlite3_last_insert_rowid(DB);
    }

    // 4. Finalize the statement
    sqlite3_finalize(stmt);
    return new_file_id;
}

int insert_data_record(sqlite3* DB,
                       long long file_id,
                       string extension, // Mapped to Extension REAL [4, 7]
                       string write_time, // Mapped to WriteTime DATETIME [4, 7]
                       int size, // Mapped to Size INTEGER [4, 7]
                       string base_folder_name) { // Mapped to BaseFolderName TEXT [4, 7]

    sqlite3_stmt* stmt = NULL;
    int rc;

    // SQL statement for Data table [4, 7]
    const char* sql = "INSERT INTO Data (FileID, Extension, WriteTime, Size, BaseFolderName) VALUES (?, ?, ?, ?, ?)";

    rc = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Data statement preparation failed: %s\n", sqlite3_errmsg(DB));
        return rc;
    }

    // 1. Bind FileID (INTEGER)
    sqlite3_bind_int64(stmt, 1, file_id);

    // 2. Bind Extension (REAL)
    sqlite3_bind_text(stmt, 2, extension.c_str(),-1, SQLITE_TRANSIENT);

    // 3. Bind WriteTime (DATETIME - usually stored as TEXT or INTEGER)
    sqlite3_bind_text(stmt, 3, write_time.c_str(), -1, SQLITE_TRANSIENT);

    // 4. Bind Size (INTEGER)
    sqlite3_bind_int(stmt, 4, size);

    // 5. Bind BaseFolderName (TEXT)
    sqlite3_bind_text(stmt, 5, base_folder_name.c_str(), -1, SQLITE_TRANSIENT);

    // Execute and finalize
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Data insertion failed: %s\n", sqlite3_errmsg(DB));
    } else {
        rc = SQLITE_OK;
    }

    sqlite3_finalize(stmt);
    return rc;
}

int insert_perm_record(sqlite3* DB,
                       long long file_id,
                       string owner,
                       string groups,
                       string others) {

    sqlite3_stmt* stmt = NULL;
    int rc;

    // SQL statement for Perm table [4, 5, 7, 8]
    const char* sql = "INSERT INTO Perm (FileID, Owner, Groups, Others) VALUES (?, ?, ?, ?)";

    rc = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Perm statement preparation failed: %s\n", sqlite3_errmsg(DB));
        return rc;
    }

    // 1. Bind FileID (INTEGER)
    sqlite3_bind_int64(stmt, 1, file_id);

    // 2. Bind Owner (TEXT)
    sqlite3_bind_text(stmt, 2, owner.c_str(), -1, SQLITE_TRANSIENT);

    // 3. Bind Groups (TEXT)
    sqlite3_bind_text(stmt, 3, groups.c_str(), -1, SQLITE_TRANSIENT);

    // 4. Bind Others (TEXT)
    sqlite3_bind_text(stmt, 4, others.c_str(), -1, SQLITE_TRANSIENT);

    // Execute and finalize
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Perm insertion failed: %s\n", sqlite3_errmsg(DB));
    } else {
        rc = SQLITE_OK;
    }

    sqlite3_finalize(stmt);
    return rc;
}