cmake_minimum_required(VERSION 3.20)

project(anashkin-i-a-23-00)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE)

find_package(Tesseract CONFIG REQUIRED)
find_package(OpenCV CONFIG REQUIRED)

add_subdirectory(prj.codeforces)

add_subdirectory(lib)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin.dbg)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin.rel)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_CURRENT_SOURCE_DIR}/bin.relwithdbg)

add_executable(test test.cpp)

target_link_libraries(test PUBLIC text_recognition)
