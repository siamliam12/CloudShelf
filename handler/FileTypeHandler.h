//
// Created by fsh33 on 10/1/2025.
//

#ifndef CLOUDSHELF_FILETYPEHANDLER_H
#define CLOUDSHELF_FILETYPEHANDLER_H
#include "string"
using namespace std;

void handleTxt(string fileName,string ext,string path,string destinationPath);
void handlePdf(string fileName,string ext,string path,string destinationPath);
void handleVideo(string fileName,string ext,string path,string destinationPath);
void handleImage(string fileName,string ext,string path,string destinationPath);

#endif //CLOUDSHELF_FILETYPEHANDLER_H