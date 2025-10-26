//
// Created by fsh33 on 10/1/2025.
//

#include "FileHandler.h"
#include "FileTypeHandler.h"
#include "../database/dbConnection.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
using namespace std;

void handleFile(vector<vector<string>> fileData,int &fileCount,string destinationPath,string databasePath) {
    for (const auto& row : fileData) {
        string fileName = row[0];
        string ext = row[1];
        string path = row[2];
        long long file_id = -1;
        //DB Block
        //connecting to database
        sqlite3* DB = InitializeDatabase(databasePath);
        // 2. CHECK FOR FAILURE: Check the return value immediately.
        if (DB == nullptr) {
            std::cerr << "Application failed to initialize database." << std::endl;
            return;
        }
        file_id = insert_file_record(DB, fileName, path);
        if (file_id <= 0) {
            fprintf(stderr, "FAILURE: File record insertion failed. Aborting related inserts.\n");
            CloseDatabase(DB);
            return;
        }
        printf("SUCCESS: File record inserted. New FileID: %lld\n", file_id);
        CloseDatabase(DB);
        //End of DB Block
        if (ext == ".txt") handleTxt(fileName,ext, path,destinationPath,databasePath,file_id);
        else if (ext == ".pdf") handlePdf(fileName,ext, path,destinationPath,databasePath,file_id);
        else if (ext == ".gif" || ext== ".mp4" || ext == ".web3") handleVideo(fileName,ext, path,destinationPath,databasePath,file_id);
        else if (ext == ".jpg" || ext == ".jpeg" || ext == ".png" || ext == ".svg") handleImage(fileName,ext, path,destinationPath,databasePath,file_id);
        else {
            cout << "Cannot handle "<< fileName << endl;
        }
    }

}
