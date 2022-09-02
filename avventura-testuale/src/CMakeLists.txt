# Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
# set vairable HEADER_LIST to the path of all the headers
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${avventura_SOURCE_DIR}/include/*.hpp")

# create library GameState composed of .ccp and headers in header list
add_library(GameState GameState.cpp ${HEADER_LIST})
target_include_directories(GameState PUBLIC ../include)


add_library(Functions Functions.cpp ${HEADER_LIST})
target_include_directories(Functions PUBLIC ../include)

add_library(Languages Languages.cpp ${HEADER_LIST})
target_include_directories(Languages PUBLIC ../include)


source_group(
	TREE "${PROJECT_SOURCE_DIR}/include"
	PREFIX "Header Files"
	FILES ${HEADER_LIST})
