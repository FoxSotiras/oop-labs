cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
project(lab3)

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(notebook_entry STATIC include/lab3/notebook_entry.hpp src/notebook_entry.cpp)
target_include_directories(notebook_entry PRIVATE include/lab3)
target_sources(notebook_entry PRIVATE src/notebook_entry_child.cpp)

add_executable("${PROJECT_NAME}" src/main.cpp)
target_link_libraries("${PROJECT_NAME}" notebook_entry)
