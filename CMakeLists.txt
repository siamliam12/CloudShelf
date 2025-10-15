cmake_minimum_required(VERSION 4.0)
project(CloudShelf)

set(CMAKE_CXX_STANDARD 20)

add_executable(CloudShelf main.cpp
        handler/FileHandler.cpp
        handler/FileHandler.h
        handler/FileTypeHandler.cpp
        handler/FileTypeHandler.h
        utils/MetaDataExtractor.cpp
        utils/MetaDataExtractor.h
        utils/MoveAndOrg.cpp
        utils/MoveAndOrg.h
)
