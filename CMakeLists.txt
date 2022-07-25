cmake_minimum_required(VERSION 3.5)
project(jsoncpp_demo)

set(CMAKE_CXX_STANDARD 11)

set(JSONCPP_HOME ${PROJECT_SOURCE_DIR})

message(STATUS"JSONCPP_HOME=${JSONCPP_HOME}")

link_directories(${JSONCPP_HOME}/jsoncpp/lib)
add_executable(jsoncpp_demo main.cpp)

target_link_libraries(jsoncpp_demo jsoncpp)