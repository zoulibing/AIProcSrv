project(AIProcSrv)
cmake_minimum_required(VERSION 2.8)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)


INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
include_directories(${Boost_INCLUDE_DIRS})


aux_source_directory(${PROJECT_SOURCE_DIR} SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/mainframe MAIN )

add_executable(AIProcSrv
                ${SRC_LIST}
                ${MAIN})
target_link_libraries(AIProcSrv  -lboost_system -lboost_thread -lpthread)
