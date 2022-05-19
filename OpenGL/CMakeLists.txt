cmake_minimum_required(VERSION 3.5)
project(OpenGL)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
file (GLOB source_files "${source_dir}/*.cpp")

# include(CTest)
# enable_testing()
add_executable(OpenGL ${source_files})
target_link_libraries(OpenGL glfw)
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
