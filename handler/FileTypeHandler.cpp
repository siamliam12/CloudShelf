//
// Created by fsh33 on 10/1/2025.
//

#include "FileTypeHandler.h"
#include "../utils/MetaDataExtractor.h"
#include "../utils/MoveAndOrg.h"
#include "../rule/BaseRule.h"
#include "../database/dbConnection.h"
#include <iostream>
#include <string>
#include <filesystem>
using namespace std::chrono_literals;
namespace fs = filesystem;

void handleTxt(string fileName,string ext,string path,string destinationPath,string databasePath,long long file_id) {
    uintmax_t fileSize = fs::file_size(path);
    GetFileData FileData(path);
    string cftime = FileData.getTime();
    auto perms = FileData.printFilePermissions();
    string owner = perms.owner;
    string groups=perms.group;
    string others=perms.others;

    Operations op(path,destinationPath);


    cout << fileName << " write time is " << cftime;
    cout << fileName << "'s size(bytes) is " << fileSize << endl;

    BaseRule baseRule(ext);
    string baseFolderName = baseRule.setDestinationFolder(fileSize);
    op.copyAndRemoveFile(fileName,baseFolderName);

    //DB Block
    //connecting to database
    sqlite3* DB = InitializeDatabase(databasePath);
    // 2. CHECK FOR FAILURE: Check the return value immediately.
    if (DB == nullptr) {
        std::cerr << "Application failed to initialize database." << std::endl;
        return;
    }
    int rc = insert_data_record(DB,file_id,ext,cftime,fileSize,baseFolderName);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Data insertion failed: %s\n", sqlite3_errmsg(DB));
        return;
    }
    rc = insert_perm_record(DB,file_id,owner,groups,others);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Data insertion failed: %s\n", sqlite3_errmsg(DB));
        return;
    }
    printf("SUCCESS: File record inserted.");
    CloseDatabase(DB);
    //End of DB Block

    cout << endl;
};
void handlePdf(string fileName,string ext,string path,string destinationPath,string databasePath,long long file_id) {
    uintmax_t fileSize = fs::file_size(path);
    GetFileData FileData(path);
    string cftime = FileData.getTime();
    auto perms = FileData.printFilePermissions();
    string owner = perms.owner;
    string groups=perms.group;
    string others=perms.others;

    Operations op(path,destinationPath);
    cout << fileName << " write time is " << cftime;
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    BaseRule baseRule(ext);
    string baseFolderName = baseRule.setDestinationFolder(fileSize);
    op.copyAndRemoveFile(fileName,baseFolderName);

    //DB Block
    //connecting to database
    sqlite3* DB = InitializeDatabase(databasePath);
    // 2. CHECK FOR FAILURE: Check the return value immediately.
    if (DB == nullptr) {
        std::cerr << "Application failed to initialize database." << std::endl;
        return;
    }
    int rc = insert_data_record(DB,file_id,ext,cftime,fileSize,baseFolderName);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Data insertion failed: %s\n", sqlite3_errmsg(DB));
        return;
    }
    rc = insert_perm_record(DB,file_id,owner,groups,others);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Data insertion failed: %s\n", sqlite3_errmsg(DB));
        return;
    }
    printf("SUCCESS: File record inserted.");
    CloseDatabase(DB);
    //End of DB Block

    cout << endl;
};
void handleVideo(string fileName,string ext,string path,string destinationPath,string databasePath,long long file_id) {
    uintmax_t fileSize = fs::file_size(path);
    GetFileData FileData(path);
    string cftime = FileData.getTime();
    auto perms = FileData.printFilePermissions();
    string owner = perms.owner;
    string groups=perms.group;
    string others=perms.others;
    Operations op(path,destinationPath);
    cout << fileName << " write time is " << cftime;
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    BaseRule baseRule(ext);
    string baseFolderName = baseRule.setDestinationFolder(fileSize);
    op.copyAndRemoveFile(fileName,baseFolderName);

    //DB Block
    //connecting to database
    sqlite3* DB = InitializeDatabase(databasePath);
    // 2. CHECK FOR FAILURE: Check the return value immediately.
    if (DB == nullptr) {
        std::cerr << "Application failed to initialize database." << std::endl;
        return;
    }
    int rc = insert_data_record(DB,file_id,ext,cftime,fileSize,baseFolderName);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Data insertion failed: %s\n", sqlite3_errmsg(DB));
        return;
    }
    rc = insert_perm_record(DB,file_id,owner,groups,others);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Data insertion failed: %s\n", sqlite3_errmsg(DB));
        return;
    }
    printf("SUCCESS: File record inserted.");
    CloseDatabase(DB);
    //End of DB Block

    cout << endl;
};
void handleImage(string fileName,string ext,string path,string destinationPath,string databasePath,long long file_id) {
    uintmax_t fileSize = fs::file_size(path);
    GetFileData FileData(path);
    string cftime = FileData.getTime();
    auto perms = FileData.printFilePermissions();
    string owner = perms.owner;
    string groups=perms.group;
    string others=perms.others;
    Operations op(path,destinationPath);
    cout << fileName << " write time is " << cftime;
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    BaseRule baseRule(ext);
    string baseFolderName = baseRule.setDestinationFolder(fileSize);
    op.copyAndRemoveFile(fileName,baseFolderName);

    //DB Block
    //connecting to database
    sqlite3* DB = InitializeDatabase(databasePath);
    // 2. CHECK FOR FAILURE: Check the return value immediately.
    if (DB == nullptr) {
        std::cerr << "Application failed to initialize database." << std::endl;
        return;
    }
    int rc = insert_data_record(DB,file_id,ext,cftime,fileSize,baseFolderName);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Data insertion failed: %s\n", sqlite3_errmsg(DB));
        return;
    }
    rc = insert_perm_record(DB,file_id,owner,groups,others);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Data insertion failed: %s\n", sqlite3_errmsg(DB));
        return;
    }
    printf("SUCCESS: File record inserted.");
    CloseDatabase(DB);
    //End of DB Block

    cout << endl;
};