cmake_minimum_required(VERSION 3.23.0)

project(avventura-testuale
	LANGUAGES CXX)

set(CMAKE_CXX_EXTENTIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src)
