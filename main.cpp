#include <iostream>
#include <sstream>
#include <string>
#include <filesystem>
#include <unordered_map>
#include <vector>
#include "handler/FileHandler.h"
#include "utils/MetaDataExtractor.h"
#include "database/dbConnection.h"
#include "rule/BaseSortFile.h"
using namespace std;

int main() {

    //connecting to database
    // sqlite3* DB = InitializeDatabase("data/cloud_shelf.db");
    //
    // // 2. CHECK FOR FAILURE: Check the return value immediately.
    // if (DB == nullptr) {
    //     std::cerr << "Application failed to initialize database." << std::endl;
    //     return EXIT_FAILURE;
    // }
    // CloseDatabase(DB);
    string databasePath = "data/cloud_shelf.db";
    string path;

    string targetPath;
    string destinationPath;
    unordered_map<int,string> filePaths;
    unordered_map<int, string> fileNames;
    cout << "Enter target folder path: ";
    getline(std::cin, path);
    targetPath = path;

    destinationPath = path;
    auto dirIter = filesystem::recursive_directory_iterator(path);
    int fileCount = 0;

    for (auto& entry : dirIter)
    {
        if (entry.is_regular_file())
        {
            ++fileCount;
            fileNames[fileCount] = entry.path().filename().string();
            filePaths[fileCount] = entry.path().string();
        }
    }
     // cout << "Path: " << path << "; | " << " Number of Files: " << fileCount << endl;
    //AI generated the solution to add data to the 2D vector
    vector<vector<string>> fileData;
    for (int i=1;i <= fileCount; i++) {
        filesystem::path p(fileNames[i]);
        string extention = p.extension().string();
        // Create a row: filename, extension and path
        vector<string> row;
        row.push_back(fileNames[i]);
        row.push_back(extention);
        row.push_back(filePaths[i]);
        // Add row to the 2D vector
        fileData.push_back(row);
        // For verification
        // cout << "[" << i << "] " << fileNames[i] << endl;
        // cout << extention << endl;
        // cout << filePaths[i] << endl;
    }
    // cout << "2D vector contents:" << endl;
    // for (const auto& row : fileData) {
    //     cout << "Filename: " << row[0] << " | Extension: " << row[1] << endl;
    // }
    cout << "Target Folder permissions: " << endl;
    GetFileData FileData(targetPath);
    FileData.printFolderPermissions(targetPath);
    cout << endl;
    cout << "Destination Folder permissions: " << endl;
    FileData.printFolderPermissions(destinationPath);
    cout << endl;
    handleFile(fileData,fileCount,destinationPath,databasePath);

    //sorting
    string choice_bool;
    string choice;
    cout << "Do you want to sort folder by time? (y/n): ";
    getline(std::cin, choice_bool);
    if (choice_bool == "y") {
        cout << "Which folder you want to sort (1-4)?:"
                "1. Pdf "
                "2. Text"
                "3. Images"
                "4. Videos";
        getline(std::cin, choice);
        sqlite3* DB = InitializeDatabase(databasePath);
        organizeStoredFiles(DB,choice,destinationPath);
        CloseDatabase(DB);
    }else {
        return 0;
    }

    return 0;
}