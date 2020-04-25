cmake_minimum_required(VERSION 3.0.0)
project(linux_learn VERSION 0.1.0)

include(CTest)
enable_testing()

AUX_SOURCE_DIRECTORY(. DIR_SRCS)
add_executable(linux_learn ${DIR_SRCS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
target_link_libraries(linux_learn pthread)
