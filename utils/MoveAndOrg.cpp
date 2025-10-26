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

void Operations::copyAndRemoveFile(string fileName, string baseFolderName) {
    fs::path source = getFileFrom;
    fs::path destination = moveFileTo;

    // Only add baseFolderName if it's not empty
    fs::path finalDestination;
    if (!baseFolderName.empty()) {
        fs::path addedBaseFolder = destination / baseFolderName;
        finalDestination = addedBaseFolder / fileName;

        // Create the subfolder
        try {
            if (fs::create_directories(addedBaseFolder)) {
                cout << addedBaseFolder << " created successfully (including any missing parents).\n";
            } else {
                cout << "Path already exists or no new directory was created.\n";
            }
        } catch (const fs::filesystem_error& e) {
            cout << e.what() << endl;
            return;
        }
    } else {
        // No subfolder, just use destination directly
        finalDestination = destination / fileName;

        // Create the destination folder
        try {
            if (fs::create_directories(destination)) {
                cout << destination << " created successfully.\n";
            } else {
                cout << "Path already exists.\n";
            }
        } catch (const fs::filesystem_error& e) {
            cout << e.what() << endl;
            return;
        }
    }

    try {
        // Copy the file
        cout << "Attempting to copy file: " << fileName << endl;
        fs::copy_file(source, finalDestination, fs::copy_options::overwrite_existing);
        cout << "File copy successful, Removing the source" << endl;

        // Remove source
        fs::remove(source);
        cout << "File moved from " << source << " to -> " << finalDestination << endl;
    } catch (const fs::filesystem_error& e) {
        cout << e.what() << endl;
    }
}