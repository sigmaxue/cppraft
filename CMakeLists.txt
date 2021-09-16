cmake_minimum_required(VERSION 2.6)
project(raft)

message(${PROJECT_BINARY_DIR})
message(${PROJECT_SOURCE_DIR})
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_BINARY_DIR})

set(YAML_CPP_PATH "3rd/yaml-cpp")

include_directories(3rd/yaml-cpp/include)

link_directories(${PROJECT_BINARY_DIR}/${YAML_CPP_PATH})

message("${PROJECT_BINARY_DIR}/${YAML_CPP_PATH}")

add_subdirectory(3rd/yaml-cpp)
add_subdirectory(src)
