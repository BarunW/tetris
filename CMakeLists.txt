cmake_minimum_required(VERSION 3.28.1)
project(tetris)


# Dependencies
include(FetchContent)
set(RAYLIB_VERSION 5.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)

	
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

#project
set(SOURCE_FILES src/main.cpp src/block.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES}) 
target_link_libraries(${PROJECT_NAME} raylib)
