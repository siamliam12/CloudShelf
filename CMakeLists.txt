cmake_minimum_required(VERSION 4.0)
project(CloudShelf)

set(CMAKE_CXX_STANDARD 20)

# Define the absolute path to your locally pulled SQLite source
# CMake accepts forward slashes even on Windows
set(SQLITE3_DIR "U:/projects/lib/libsqlite3")

add_executable(CloudShelf main.cpp
        handler/FileHandler.cpp
        handler/FileHandler.h
        handler/FileTypeHandler.cpp
        handler/FileTypeHandler.h
        utils/MetaDataExtractor.cpp
        utils/MetaDataExtractor.h
        utils/MoveAndOrg.cpp
        utils/MoveAndOrg.h
        rule/BaseRule.cpp
        rule/BaseRule.h
        database/dbConnection.cpp
        database/dbConnection.h

        ${SQLITE3_DIR}/sqlite3.c
        utils/FileOrganizer.cpp
        utils/FileOrganizer.h
        rule/BaseSortFile.cpp
        rule/BaseSortFile.h
        #        database/dbConnection.cpp
)
target_include_directories(CloudShelf PRIVATE ${SQLITE3_DIR})
