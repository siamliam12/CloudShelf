

#ifndef CLOUDSHELF_METADATAEXTRACTOR_H
#define CLOUDSHELF_METADATAEXTRACTOR_H
#include <string>
using namespace std;
class GetFileData {
    public:
    explicit GetFileData(string path);
    string getTime() const;
    void printFilePermissions();
    void printFolderPermissions(string pathToCheckPerm);
private:
    std::string filePath;
};

#endif //CLOUDSHELF_METADATAEXTRACTOR_H