cmake_minimum_required(VERSION 3.16.3)
project(AdasCoord VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE Debug)
set(EXECUTABLE_OUTPUT_PATH ../bin/)

set(LIB_LIST )
set(SRC_LIST )

aux_source_directory(AdasCoord/  SRC_LIST)

set(SRC_LIST main.cpp ${SRC_LIST})

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${LIB_LIST})

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
