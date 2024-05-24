cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(lab2)
set(SOURCE src/dynamic_array.cpp
           src/rational_number.cpp
           src/main.cpp)
add_executable("${PROJECT_NAME}" "${SOURCE}")
