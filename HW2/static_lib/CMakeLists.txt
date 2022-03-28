cmake_minimum_required(VERSION 3.0.0)
project(dist_no_parallel)

set(DIST_NO_PARALLEL_LIB_LIBRARIES)
set(DIST_NO_PARALLEL_LIB_INCLUDE_DIRS)

file(GLOB SOURCES *.c)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${PROJECT_NAME} STATIC ${SOURCES})  # создаем библиотеку
target_link_libraries(${PROJECT_NAME} PUBLIC m)  # подключаем в библиотекую math.h

set(DIST_NO_PARALLEL_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)  # пробрасываем переменные наверх
set(DIST_NO_PARALLEL_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)
