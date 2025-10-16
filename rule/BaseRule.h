//
// Created by fsh33 on 10/15/2025.
//

#ifndef CLOUDSHELF_BASERULE_H
#define CLOUDSHELF_BASERULE_H

#include <string>
using namespace std;

class BaseRule {
public:
    explicit BaseRule(string fileExtension);

    string setDestinationFolder(int fileSize);
private:
    string ext;
};


#endif //CLOUDSHELF_BASERULE_H