#include <iostream>
#include <sstream>
#include <string>
#include <filesystem>
#include <unordered_map>
#include <vector>
#include "handler/FileHandler.h"
#include "utils/MetaDataExtractor.h"
using namespace std;

int main() {
    string path;
    string path2;
    string targetPath;
    string destinationPath;
    unordered_map<int,string> filePaths;
    unordered_map<int, string> fileNames;
    cout << "Enter target folder path: ";
    getline(std::cin, path);
    targetPath = path;
    cout << "Enter destination folder path: ";
    getline(std::cin, path2);
    destinationPath = path2;
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
    handleFile(fileData,fileCount);
    return 0;
}