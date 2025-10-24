//
// Created by fsh33 on 10/24/2025.
//

#include "BaseSortFile.h"
#include "../utils/FileOrganizer.h"
#include <sqlite3.h>
#include <iostream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

fs::path operator/(const string & lhs, const string & rhs);

void organizeStoredFiles(sqlite3* DB,string choice,string destinationPath) {
    cout << "\n=== Starting File Organization ===" << endl;
    string addedBase;
    if (choice == "1") {
        addedBase = "PDFs";
    }else if (choice == "2") {
        addedBase = "Texts";
    }else if (choice == "3") {
        addedBase = "Images";
    }else if (choice == "4") {
        addedBase = "Videos";
    }
    fs::path addedBaseFolder = fs::path(destinationPath) / addedBase;
    string addedBaseFolderStr = addedBaseFolder.string();
    cout << "destination path: " << addedBaseFolder << endl;
    // Create the organizer
    FileOrganizer organizer(DB, addedBaseFolderStr);
    string sourcePath = addedBaseFolderStr;
    // Option 1: Organize all files by newest first
    organizer.organizeFilesByTime(true,sourcePath);  // true = newest first

    // Option 2: Organize all files by oldest first
    // organizer.organizeFilesByTime(false);  // false = oldest first

    // Option 3: Archive files older than a specific date
    // organizer.organizeOldFiles("2025-10-01 00:00:00");

    // Option 4: Move only recent files
    // organizer.organizeNewFiles("2025-10-20 00:00:00");

    cout << "=== Organization Complete ===" << endl;
}
