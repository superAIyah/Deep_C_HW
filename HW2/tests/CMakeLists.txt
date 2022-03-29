cmake_minimum_required(VERSION 3.14)
project(tests_lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

file(GLOB SOURCES *.cpp)  # сами тесты

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${DIST_NO_PARALLEL_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${DIST_NO_PARALLEL_LIB_LIBRARIES} GTest::Main)  # подключаем статическую библиотеку

target_include_directories(${PROJECT_NAME} PUBLIC ${DIST_PARALLEL_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${DIST_PARALLEL_LIB_LIBRARIES} GTest::Main)  # подключаем динамическую библиотеку