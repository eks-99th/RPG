cmake_minimum_required(VERSION 3.10)

# Set the project name - 
project(CppCodeAlong)
set(CMAKE_C_STANDARD 11)  # Use C11 standard
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-extra-arg=-I/usr/include/c++/11;-extra-arg=-I/usr/include/x86_64-linux-gnu/c++/11;-extra-arg=-I/usr/include;-extra-arg=-fdiagnostics-format=json")
# Add an executable
add_executable(CppCodeAlong main.cpp)