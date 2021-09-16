set(RAFT_BIN raft_demo)
add_executable(${RAFT_BIN} demo.cc)

target_link_libraries(${RAFT_BIN} libyaml-cpp.a)
add_dependencies(${RAFT_BIN} yaml-cpp)

set_target_properties(${RAFT_BIN} PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
#install(TARGETS ${RAFT_BIN} DESTINATION ${CMAKE_SOURCE_DIR}/bin)
