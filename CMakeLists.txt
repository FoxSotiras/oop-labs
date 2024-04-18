cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(lab1)
set(SOURCE src/book.cpp
           src/lib_card.cpp
           src/main.cpp)
add_executable("${PROJECT_NAME}" "${SOURCE}")
