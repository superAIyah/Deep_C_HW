cmake_minimum_required(VERSION 3.0.0)
project(main)

#set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra -Werror -ldl")
#set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-ldl")

add_subdirectory(static_lib)  # собери cmakelists библиотек
add_subdirectory(dynamic_lib)

message("main: DIST_NO_PARALLEL_LIB_LIBRARIES = ${DIST_NO_PARALLEL_LIB_LIBRARIES}")  # проверка зависимостей
message("main: DIST_NO_PARALLEL_LIB_INCLUDE_DIRS = ${DIST_NO_PARALLEL_LIB_INCLUDE_DIRS}")
message("main: DIST_PARALLEL_LIB_LIBRARIES = ${DIST_PARALLEL_LIB_LIBRARIES}")
message("main: DIST_PARALLEL_LIB_INCLUDE_DIRS = ${DIST_PARALLEL_LIB_INCLUDE_DIRS}")

add_executable(${PROJECT_NAME} main.c)  # создаем бинарник

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

target_include_directories(${PROJECT_NAME} PUBLIC ${DIST_NO_PARALLEL_LIB_INCLUDE_DIRS} GTest::Main)
target_link_libraries(${PROJECT_NAME} PRIVATE ${DIST_NO_PARALLEL_LIB_LIBRARIES})  # подключаем статическую библиотеку

target_include_directories(${PROJECT_NAME} PUBLIC ${DIST_PARALLEL_LIB_INCLUDE_DIRS} GTest::Main)
target_link_libraries(${PROJECT_NAME} PRIVATE ${DIST_PARALLEL_LIB_LIBRARIES})  # подключаем динамическую библиотеку

add_subdirectory(tests)