find_package(Tesseract CONFIG REQUIRED)
find_package(OpenCV CONFIG REQUIRED)

set(CMAKE_VERBOSE_MAKEFILE True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin.dbg)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin.rel)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_CURRENT_SOURCE_DIR}/bin.relwithdbg)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE opencv_core opencv_imgproc opencv_imgcodecs opencv_highgui Tesseract::libtesseract) 