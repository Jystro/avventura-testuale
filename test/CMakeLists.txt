# Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test test.cpp)

target_compile_features(test PRIVATE cxx_std_14)

target_link_libraries(test PRIVATE InputParser)
