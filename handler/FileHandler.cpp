//
// Created by fsh33 on 10/1/2025.
//

#include "FileHandler.h"
#include "FileTypeHandler.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
using namespace std;

void handleFile(vector<vector<string>> fileData,int &fileCount) {
    for (const auto& row : fileData) {
        string fileName = row[0];
        string ext = row[1];
        string path = row[2];
        // for (int i=0; i <= fileCount; i++) {
        if (ext == ".txt") handleTxt(fileName,ext, path);
        else if (ext == ".pdf") handlePdf(fileName,ext, path);
        else if (ext == ".gif" || ext== ".mp4" || ext == ".web3") handleVideo(fileName,ext, path);
        else if (ext == ".jpg" || ext == ".jpeg" || ext == ".png" || ext == ".svg") handleImage(fileName,ext, path);
        else {
            cout << "Cannot handle "<< fileName << endl;
        }
    }

    // }
}
