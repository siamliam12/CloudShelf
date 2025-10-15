//
// Created by fsh33 on 10/15/2025.
//

#ifndef CLOUDSHELF_MOVEANDORG_H
#define CLOUDSHELF_MOVEANDORG_H
#include <string>
using namespace std;

class Operations {
    public:
    Operations(string targetPath,string desPath);
    void copyAndRemoveFile(string fileName);
private:
    string getFileFrom;
    string moveFileTo;
};


#endif //CLOUDSHELF_MOVEANDORG_H