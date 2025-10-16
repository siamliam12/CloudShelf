//
// Created by fsh33 on 10/15/2025.
//

#include "BaseRule.h"
#include <iostream>

using namespace std;
BaseRule::BaseRule(string fileExtension) {
    ext = fileExtension;
};

string BaseRule::setDestinationFolder(int fileSize) {
    string baseFolder;
    if (ext == ".txt") { // NOLINT(*-branch-clone)
        baseFolder = "Texts";
    }
    else if (ext == ".pdf") {
        baseFolder = "PDFs";
    }
    else if (ext == ".gif") {
        if (fileSize <= 100000000) {
            baseFolder = "GIFs";
        }else {
            baseFolder = "Videos";
        }
    }
    else if (ext == ".mp4" || ext == ".web3") {
        if (fileSize <= 240000000) {
            baseFolder = "short videos";
        }else if (fileSize > 700000000) {
            baseFolder = "Movies or big videos";
        }
        else {
            baseFolder = "Videos";
        }
    }
    else if (ext == ".jpg" || ext == ".jpeg" || ext == ".png" || ext == ".svg") {
        baseFolder = "Images";
    }else {
        baseFolder = "/";
    }
    return baseFolder;
}