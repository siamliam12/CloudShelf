//
// Created by fsh33 on 10/1/2025.
//

#include "FileTypeHandler.h"
#include "../utils/MetaDataExtractor.h"
#include "../utils/MoveAndOrg.h"
#include "../rule/BaseRule.h"
#include <iostream>
#include <string>
#include <filesystem>
using namespace std::chrono_literals;
namespace fs = filesystem;

void handleTxt(string fileName,string ext,string path,string destinationPath) {
    uintmax_t fileSize = fs::file_size(path);
    GetFileData FileData(path);
    string cftime = FileData.getTime();
    FileData.printFilePermissions();

    Operations op(path,destinationPath);


    cout << fileName << " write time is " << cftime;
    cout << fileName << "'s size(bytes) is " << fileSize << endl;

    BaseRule baseRule(ext);
    string baseFolderName = baseRule.setDestinationFolder(fileSize);
    op.copyAndRemoveFile(fileName,baseFolderName);

    cout << endl;
};
void handlePdf(string fileName,string ext,string path,string destinationPath) {
    uintmax_t fileSize = fs::file_size(path);
    GetFileData FileData(path);
    string cftime = FileData.getTime();
    FileData.printFilePermissions();
    Operations op(path,destinationPath);
    cout << fileName << " write time is " << cftime;
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    BaseRule baseRule(ext);
    string baseFolderName = baseRule.setDestinationFolder(fileSize);
    op.copyAndRemoveFile(fileName,baseFolderName);
    cout << endl;
};
void handleVideo(string fileName,string ext,string path,string destinationPath) {
    uintmax_t fileSize = fs::file_size(path);
    GetFileData FileData(path);
    string cftime = FileData.getTime();
    FileData.printFilePermissions();
    Operations op(path,destinationPath);
    cout << fileName << " write time is " << cftime;
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    BaseRule baseRule(ext);
    string baseFolderName = baseRule.setDestinationFolder(fileSize);
    op.copyAndRemoveFile(fileName,baseFolderName);
    cout << endl;
};
void handleImage(string fileName,string ext,string path,string destinationPath) {
    uintmax_t fileSize = fs::file_size(path);
    GetFileData FileData(path);
    string cftime = FileData.getTime();
    FileData.printFilePermissions();
    Operations op(path,destinationPath);
    cout << fileName << " write time is " << cftime;
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    BaseRule baseRule(ext);
    string baseFolderName = baseRule.setDestinationFolder(fileSize);
    op.copyAndRemoveFile(fileName,baseFolderName);
    cout << endl;
};