file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${avventura-testuale_SOURCE_DIR}/include/*.hpp")
#set(HEADER_LIST "${avventura-testuale_SOURCE_DIR}/include/InputParser.hpp")

add_library(InputParser InputParser.cpp ${HEADER_LIST})

target_include_directories(InputParser PUBLIC ../include)

source_group(
	TREE "${PROJECT_SOURCE_DIR}/include"
	PREFIX "Header Files"
	FILES ${HEADER_LIST})

add_executable(avventura-testuale main.cpp)

target_link_libraries(avventura-testuale PRIVATE InputParser)
