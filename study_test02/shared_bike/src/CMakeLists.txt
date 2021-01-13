cmake_minimum_required(VERSION 2.8)

project(shared_bike)

include_directories(../third/include/)
include_directories(./common)

link_directories(../third/lib/iniparser)
link_directories(./common)

aux_source_directory(${PROJECT_SOURCE_DIR} SOURCE_FILES)

add_executable(shared_bike ${SOURCE_FILES})

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

target_link_libraries(shared_bike iniparser)
target_link_libraries(shared_bike common)

add_subdirectory(common)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})
install (TARGETS shared_bike DESTINATION bin)


