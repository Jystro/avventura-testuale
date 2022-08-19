# set vairable HEADER_LIST to the path of all the headers
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${avventura_SOURCE_DIR}/include/*.hpp")

# create library InputParser composed of .ccp and headers in header list
add_library(InputParser InputParser.cpp ${HEADER_LIST})

target_include_directories(InputParser PUBLIC ../include)

# create library GameState
add_library(GameState GameState.cpp ${HEADER_LIST})

target_include_directories(GameState PUBLIC ../include)

source_group(
	TREE "${PROJECT_SOURCE_DIR}/include"
	PREFIX "Header Files"
	FILES ${HEADER_LIST})
