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

void handleFile(vector<vector<string>> fileData,int &fileCount,string destinationPath) {
    for (const auto& row : fileData) {
        string fileName = row[0];
        string ext = row[1];
        string path = row[2];
        if (ext == ".txt") handleTxt(fileName,ext, path,destinationPath);
        else if (ext == ".pdf") handlePdf(fileName,ext, path,destinationPath);
        else if (ext == ".gif" || ext== ".mp4" || ext == ".web3") handleVideo(fileName,ext, path,destinationPath);
        else if (ext == ".jpg" || ext == ".jpeg" || ext == ".png" || ext == ".svg") handleImage(fileName,ext, path,destinationPath);
        else {
            cout << "Cannot handle "<< fileName << endl;
        }
    }

}
