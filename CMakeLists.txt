# Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
cmake_minimum_required(VERSION 3.23)

project(avventura
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENTIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Doxygen)
if(Doxygen_FOUND)
	add_subdirectory(docs)
endif()


add_subdirectory(src)


add_executable(avventura main.cpp)
target_link_libraries(avventura PUBLIC GameState Functions Languages)
