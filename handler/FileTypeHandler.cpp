//
// Created by fsh33 on 10/1/2025.
//

#include "FileTypeHandler.h"
#include "../utils/MetaDataExtractor.h"

#include <chrono>
#include <iostream>
#include <string>
#include <filesystem>
using namespace std::chrono_literals;
namespace fs = filesystem;

void handleTxt(string fileName,string ext,string path) {
    uintmax_t fileSize = fs::file_size(path);
    GetFileData FileData(path);
    string cftime = FileData.getTime();
    FileData.printFilePermissions();
    cout << fileName << " write time is " << cftime;
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    cout << endl;
};
void handlePdf(string fileName,string ext,string path) {
    uintmax_t fileSize = fs::file_size(path);
    GetFileData FileData(path);
    string cftime = FileData.getTime();
    FileData.printFilePermissions();
    cout << fileName << " write time is " << cftime;
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    cout << endl;
};
void handleVideo(string fileName,string ext,string path) {
    uintmax_t fileSize = fs::file_size(path);
    GetFileData FileData(path);
    string cftime = FileData.getTime();
    FileData.printFilePermissions();
    cout << fileName << " write time is " << cftime;
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    cout << endl;
};
void handleImage(string fileName,string ext,string path) {
    uintmax_t fileSize = fs::file_size(path);
    GetFileData FileData(path);
    string cftime = FileData.getTime();
    FileData.printFilePermissions();
    cout << fileName << " write time is " << cftime;
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    cout << endl;
};