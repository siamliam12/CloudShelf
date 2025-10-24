

#ifndef CLOUDSHELF_METADATAEXTRACTOR_H
#define CLOUDSHELF_METADATAEXTRACTOR_H
#include <string>
using namespace std;
struct Permissions {
    string owner;
    string group;
    string others;
};
class GetFileData {
    public:
    explicit GetFileData(string path);
    string getTime() const;
    Permissions printFilePermissions();
    void printFolderPermissions(string pathToCheckPerm);
private:
    std::string filePath;
};

#endif //CLOUDSHELF_METADATAEXTRACTOR_H