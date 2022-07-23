cmake_minimum_required(VERSION 3.22)
project(lab18_1)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)
add_compile_options(-pthread)
add_executable(lab18_1 main.cpp notebook.hpp notebook.cpp)
target_link_libraries(lab18_1 PRIVATE Threads::Threads)
