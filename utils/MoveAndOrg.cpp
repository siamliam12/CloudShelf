//
// Created by fsh33 on 10/15/2025.
//

#include "MoveAndOrg.h"
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

Operations::Operations(string targetPath,string desPath) {
    getFileFrom = targetPath;
    moveFileTo = desPath;
}

void Operations::copyAndRemoveFile(string fileName,string baseFolderName) {
    fs::path  source= getFileFrom;
    fs::path  destination= moveFileTo;
    fs::path addedBaseFolder = destination /baseFolderName ;
    fs::path getFullDesPath = addedBaseFolder/ fileName;

    //making sure the destination exists
    fs::create_directories(destination);
    try {
        if (fs::create_directories(addedBaseFolder))
        {
            cout << addedBaseFolder<<" created successfully (including any missing parents).\n";
        }
        else
        {
            cout << "Path already exists or no new directory was created.\n";
        }
        //copy the file
        cout << "Attempting to copy file: " << fileName<< endl;
        fs::copy_file(source, getFullDesPath);
        cout << "File copy successful, Removing the source" << endl;
        fs::remove_all(source);
        cout << "File moved from " << source << " to -> " << destination << endl;
    } catch (const fs::filesystem_error& e) {
        cout<<e.what()<<endl;
    }
}