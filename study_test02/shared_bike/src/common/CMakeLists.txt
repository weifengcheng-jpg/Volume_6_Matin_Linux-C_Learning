cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SOURCE_SOMMON_FILES)

ADD_LIBRARY(common ${SOURCE_SOMMON_FILES})

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

#将指定目录添加到编译器的头文件搜索路径之下
include_directories(../../third/include/)


#将指定目录添加到需要连接的库文件目录之下
link_directories(../../third/lib/iniparser)
link_directories(../../third/lib/log4cpp)



#该指令的作用为将目标文件与库文件进行链接
target_link_libraries(common iniparser)
target_link_libraries(common log4cpp)
target_link_libraries(common pthread)
target_link_libraries(common dl)



