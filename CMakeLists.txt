cmake_minimum_required(VERSION 3.8)

project (TestAnalaysis)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-style=file;-checks=*") # not working
add_executable(sample sample/sample.cpp)
set_target_properties(sample PROPERTIES
    VS_GLOBAL_RunCodeAnalysis true
    # Use clangtidy
    VS_GLOBAL_EnableClangTidyCodeAnalysis true
    VS_GLOBAL_ClangTidyChecks -checks=-*,modernize-*,-modernize-use-trailing-return-type
)