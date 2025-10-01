//
// Created by fsh33 on 10/1/2025.
//

#include "FileTypeHandler.h"
#include <chrono>
#include <iostream>
#include <string>
#include <filesystem>
using namespace std::chrono_literals;
namespace fs = filesystem;

void handleTxt(string fileName,string ext,string path) {
    uintmax_t fileSize = fs::file_size(path);

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

    // read back from the filesystem
    fs::file_time_type ft = fs::last_write_time(path);
    // Try to convert to system_clock using duration cast
    auto sctp = chrono::system_clock::now() + (ft - fs::file_time_type::clock::now());

    time_t cftime = chrono::system_clock::to_time_t(sctp);
    // cout << ctime(&cftime) << endl;
    if (cftime) {
        cout << fileName << " write time is " << ctime(&cftime);
    } else {
        cout << fileName << " write time conversion failed." << endl;
    }

    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    cout << endl;
};
void handlePdf(string fileName,string ext,string path) {
    uintmax_t fileSize = fs::file_size(path);
    // read back from the filesystem
    fs::file_time_type ft = fs::last_write_time(path);
    // Try to convert to system_clock using duration cast
    auto sctp = chrono::system_clock::now() + (ft - fs::file_time_type::clock::now());

    time_t cftime = chrono::system_clock::to_time_t(sctp);
    // cout << ctime(&cftime) << endl;
    if (cftime) {
        cout << fileName << " write time is " << ctime(&cftime);
    } else {
        cout << fileName << " write time conversion failed." << endl;
    }
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    cout << endl;
};
void handleVideo(string fileName,string ext,string path) {
    uintmax_t fileSize = fs::file_size(path);
    // read back from the filesystem
    fs::file_time_type ft = fs::last_write_time(path);
    // Try to convert to system_clock using duration cast
    auto sctp = chrono::system_clock::now() + (ft - fs::file_time_type::clock::now());

    time_t cftime = chrono::system_clock::to_time_t(sctp);
    // cout << ctime(&cftime) << endl;
    if (cftime) {
        cout << fileName << " write time is " << ctime(&cftime);
    } else {
        cout << fileName << " write time conversion failed." << endl;
    }
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    cout << endl;
};
void handleImage(string fileName,string ext,string path) {
    uintmax_t fileSize = fs::file_size(path);
    // read back from the filesystem
    fs::file_time_type ft = fs::last_write_time(path);
    // Try to convert to system_clock using duration cast
    auto sctp = chrono::system_clock::now() + (ft - fs::file_time_type::clock::now());

    time_t cftime = chrono::system_clock::to_time_t(sctp);
    // cout << ctime(&cftime) << endl;
    if (cftime) {
        cout << fileName << " write time is " << ctime(&cftime) ;
    } else {
        cout << fileName << " write time conversion failed." << endl;
    }
    cout << fileName << "'s size(bytes) is " << fileSize << endl;
    cout << endl;
};