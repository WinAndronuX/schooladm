cmake_minimum_required(VERSION 3.10)

project(SchoolAdm VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(schooladm
    src/main.cpp
    src/menu.cpp
    src/reports.cpp
    src/utils.cpp
)

target_include_directories(schooladm
    PUBLIC
        include
)