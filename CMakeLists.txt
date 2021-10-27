cmake_minimum_required(VERSION 3.8)

project (TestAnalaysis)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-style=file;-checks=*")

add_executable(sample sample/sample.cpp)