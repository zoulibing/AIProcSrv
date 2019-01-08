project(AIProcSrv)
cmake_minimum_required(VERSION 2.8)
set(OpenCV_DIR /usr/local/share/OpenCV)
find_package(OpenCV  REQUIRED)
find_package(Boost REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -W")


set(MXNET_HOME "/home/li/zoulb/mxnet_cpp/mxnet")
#set(MXNET_HOME "/home/rock/Downloads/mxnet")
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(
    ${MXNET_HOME}/3rdparty/dmlc-core/include
    ${MXNET_HOME}/3rdparty/nnvm/include
    ${MXNET_HOME}/include
    ${MXNET_HOME}/cpp-package/include
    )

link_directories(${MXNET_HOME}/lib)

aux_source_directory(${PROJECT_SOURCE_DIR} SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/mainframe MAIN )
aux_source_directory(${PROJECT_SOURCE_DIR}/src/rtmpPubliser RTMPPUBLISHER )


add_executable(AIProcSrv
                ${SRC_LIST}
                ${MAIN}
                ${RTMPPUBLISHER})



target_link_libraries(AIProcSrv  -lboost_system -lboost_thread -lpthread -lX11 mxnet x264 rtmp asound faac ${OpenCV_LIBS})
