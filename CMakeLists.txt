project(AIProcSrv)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(AIProcSrv ${SRC_LIST})
