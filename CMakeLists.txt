cmake_minimum_required(VERSION 4.0)
project(CloudShelf)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.10.0/mingw_64/lib/cmake/Qt6" ${CMAKE_PREFIX_PATH})
# Define the absolute path to your locally pulled SQLite source
# CMake accepts forward slashes even on Windows
set(SQLITE3_DIR "U:/projects/lib/libsqlite3")
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
set(CMAKE_AUTOMOC ON) # Handles the Q_OBJECT macro (Signals/Slots) [18, 19, 22]
set(CMAKE_AUTOUIC ON) # Handles the .ui files (Graphical designs) [18, 19, 23]
set(CMAKE_AUTORCC ON) # Handles resource files (.qrc) [18, 19]
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
target_link_libraries(CloudShelf
        Qt6::Core
        Qt6::Widgets
)
target_include_directories(CloudShelf PRIVATE ${SQLITE3_DIR})
