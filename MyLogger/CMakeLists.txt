# cmake_minimum_required(VERSION 3.0.0)
# project(MyLogger VERSION 0.1.0)

# include(CTest)
# enable_testing()

# add_executable(MyLogger main.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

cmake_minimum_required (VERSION 3.5)

project (MyLogger)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable (MyLogger ${source_files})
