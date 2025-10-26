//
// Created by fsh33 on 10/16/2025.
//

#ifndef CLOUDSHELF_DBCONNECTION_H
#define CLOUDSHELF_DBCONNECTION_H
#include <sqlite3.h>
#include <string>
using namespace std;
// Function to initialize the database file and create the schema
// Returns an open sqlite3* connection handle, or nullptr on failure.
sqlite3* InitializeDatabase(string dbFilePath);

// Function to manually close the database connection
void CloseDatabase(sqlite3* DB);
long long insert_file_record(sqlite3* DB, string name, string path);
int insert_data_record(sqlite3* DB,
                       long long file_id,
                       string extension, // Mapped to Extension REAL [4, 7]
                       string write_time, // Mapped to WriteTime DATETIME [4, 7]
                       int size, // Mapped to Size INTEGER [4, 7]
                       string base_folder_name);
int insert_perm_record(sqlite3* DB,
                       long long file_id,
                       string owner,
                       string groups,
                       string others);
#endif //CLOUDSHELF_DBCONNECTION_H