#include <iostream>
#include <sstream>
#include <string>
#include <filesystem>
#include <unordered_map>
#include <vector>
#include "handler/FileHandler.h"
using namespace std;
int main() {
    string path;
    unordered_map<int,string> filePaths;
    unordered_map<int, string> fileNames;
    cout << "Enter folder path: ";
    getline(std::cin, path);
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
    cout << "2D vector function calling:" << endl;
    handleFile(fileData,fileCount);
    return 0;
}