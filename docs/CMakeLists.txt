set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_GENERATE_HTML YES)

doxygen_add_docs(docs ${PROJECT_SOURCE_DIR}/main.cpp ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/include)
