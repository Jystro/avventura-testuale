# Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
cmake_minimum_required(VERSION 3.23)

project(avventura
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENTIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


add_subdirectory(src)


add_executable(avventura main.cpp)
target_link_libraries(avventura PUBLIC GameState)
