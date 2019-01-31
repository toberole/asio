cmake_minimum_required(VERSION 3.13)
project(asio)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src SRC_FILES)

add_executable(asio ${SRC_FILES})

target_link_libraries(asio pthread)