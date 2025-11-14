cmake_minimum_required(VERSION 3.10)

project(SchoolAdm VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(listview STATIC
    lib/listview/src/listview.c
)

target_include_directories(listview
    PUBLIC
        lib/listview/include
)

add_executable(schooladm
    src/main.cpp
    src/menu.cpp
    src/reports.cpp
    src/utils.cpp
    src/students.cpp
    src/users.cpp
    src/login.cpp
    src/subjects.cpp
)

target_include_directories(schooladm
    PUBLIC
        include
)

target_link_libraries(schooladm PRIVATE listview)
