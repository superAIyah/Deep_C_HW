cmake_minimum_required(VERSION 3.0.0)
project(main)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra -Werror")

add_subdirectory(static_lib)

message("main: DIST_NO_PARALLEL_LIB_LIBRARIES = ${DIST_NO_PARALLEL_LIB_LIBRARIES}")
message("main: DIST_NO_PARALLEL_LIB_INCLUDE_DIRS = ${DIST_NO_PARALLEL_LIB_INCLUDE_DIRS}")

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE ${DIST_NO_PARALLEL_LIB_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${DIST_NO_PARALLEL_LIB_INCLUDE_DIRS})