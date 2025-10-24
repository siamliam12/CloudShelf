//
// Created by fsh33 on 10/24/2025.
//

#ifndef CLOUDSHELF_BASESORTFILE_H
#define CLOUDSHELF_BASESORTFILE_H
#include <sqlite3.h>
#include <string>
using namespace std;
void organizeStoredFiles(sqlite3* DB,string choice,string destinationPath);

#endif //CLOUDSHELF_BASESORTFILE_H