//
// Created by fsh33 on 10/1/2025.
//

#include "FileTypeHandler.h"
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

void handleTxt(string fileName,string ext,string path) {
    uintmax_t fileSize = fs::file_size(path);
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
};
void handlePdf(string fileName,string ext,string path) {
    uintmax_t fileSize = fs::file_size(path);
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
};
void handleVideo(string fileName,string ext,string path) {
    uintmax_t fileSize = fs::file_size(path);
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
};
void handleImage(string fileName,string ext,string path) {
    uintmax_t fileSize = fs::file_size(path);
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
};