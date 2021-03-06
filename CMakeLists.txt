cmake_minimum_required(VERSION 3.21)
project(raft)

message(${PROJECT_BINARY_DIR})
message(${PROJECT_SOURCE_DIR})
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(YAML_CPP_PATH "3rd/yaml-cpp")
set(RPC_CPP_PATH "3rd/ananas")
set(FMT_PATH "3rd/fmt")

include_directories(3rd)
include_directories(3rd/yaml-cpp/include)

link_directories(${PROJECT_BINARY_DIR}/${YAML_CPP_PATH})
link_directories(${PROJECT_BINARY_DIR}/${FMT_PATH})
link_directories(${PROJECT_SOURCE_DIR}/${RPC_CPP_PATH}/bin)

message("${PROJECT_BINARY_DIR}/${YAML_CPP_PATH}")

add_subdirectory(${YAML_CPP_PATH})
add_subdirectory(${RPC_CPP_PATH})
add_subdirectory(${FMT_PATH})
add_subdirectory(src)
