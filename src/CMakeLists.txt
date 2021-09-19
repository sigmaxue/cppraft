set(RAFT_BIN raft)

aux_source_directory(. SRCS)
add_executable(${RAFT_BIN} ${SRCS})

target_link_libraries(${RAFT_BIN}
libyaml-cpp.a
libananas_rpc.a
libananas_net.a
libananas_util.a
libfmt.a
pthread
)
add_dependencies(${RAFT_BIN} fmt yaml-cpp ananas_rpc)

set_target_properties(${RAFT_BIN} PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
#install(TARGETS ${RAFT_BIN} DESTINATION ${CMAKE_SOURCE_DIR}/bin)
