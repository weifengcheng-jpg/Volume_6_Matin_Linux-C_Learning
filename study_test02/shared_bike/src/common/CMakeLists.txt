cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SOURCE_SOMMON_FILES)

ADD_LIBRARY(common ${SOURCE_SOMMON_FILES})

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

include_directories(../../third/include/)
link_directories(../../third/lib/iniparser)

target_link_libraries(common iniparser)
target_link_libraries(common dl)



