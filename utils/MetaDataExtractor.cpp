#include "MetaDataExtractor.h"
#include <chrono>
#include <iostream>
#include <string>
#include <filesystem>
using namespace std::chrono_literals;
using namespace std;
string targetPath;
namespace fs = filesystem;
GetFileData::GetFileData(string path) {
    filePath = path;
}

/* AI Generated code block
*    fs::path path = "yourfile.pdf"; // Set your filename here
fs::file_time_type ft = fs::last_write_time(path);

// Try to convert to system_clock using duration cast
auto sctp = chrono::system_clock::now() + (ft - fs::file_time_type::clock::now());

time_t cftime = chrono::system_clock::to_time_t(sctp);

if (auto* tm = localtime(&cftime)) {
    cout << "File write time is " << put_time(tm, "%F %T") << endl;
} else {
    cout << "File write time conversion failed." << endl;
}
 */
string GetFileData::getTime() const {
    // read back from the filesystem
    fs::file_time_type ft = fs::last_write_time(filePath);
    // Try to convert to system_clock using duration cast
    auto sctp =chrono::system_clock::now() + (ft - fs::file_time_type::clock::now());

    time_t cftime = chrono::system_clock::to_time_t(sctp);
    if (cftime) {
        return ctime(&cftime);
    } else {
        return " write time conversion failed.";
    }
}

void GetFileData::printFilePermissions() {
    fs::perms p = fs::status(filePath).permissions();
    //AI Generated
    cout << "File Data: " << endl;
    cout << "Owner: "
        << ((p & fs::perms::owner_read)  != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::owner_exec)  != fs::perms::none ? "x" : "-")
        << ", Group: "
        << ((p & fs::perms::group_read)  != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::group_exec)  != fs::perms::none ? "x" : "-")
        << ", Others: "
        << ((p & fs::perms::others_read)  != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::others_exec)  != fs::perms::none ? "x" : "-")
        << std::endl;
}
void GetFileData::printFolderPermissions(string pathToCheckPerm) {
    //AI Generated
    cout << "Path: "<< pathToCheckPerm << endl;
    fs::perms folderPerm = fs::status(pathToCheckPerm).permissions();
    cout << "Folder permission info: " << endl;
    cout << "Owner: "
    << ((folderPerm & fs::perms::owner_read)  != fs::perms::none ? "r" : "-")
    << ((folderPerm & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
    << ((folderPerm & fs::perms::owner_exec)  != fs::perms::none ? "x" : "-")
    << ", Group: "
    << ((folderPerm & fs::perms::group_read)  != fs::perms::none ? "r" : "-")
    << ((folderPerm & fs::perms::group_write) != fs::perms::none ? "w" : "-")
    << ((folderPerm & fs::perms::group_exec)  != fs::perms::none ? "x" : "-")
    << ", Others: "
    << ((folderPerm & fs::perms::others_read)  != fs::perms::none ? "r" : "-")
    << ((folderPerm & fs::perms::others_write) != fs::perms::none ? "w" : "-")
    << ((folderPerm & fs::perms::others_exec)  != fs::perms::none ? "x" : "-")
    << std::endl;
}
