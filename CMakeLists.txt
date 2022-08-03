cmake_minimum_required(VERSION 3.8.0)
project(CS100_Lab7 VERSION 7.0.0)

add_subdirectory(${CMAKE_BINARY_DIR}/../googletest)

set(CMAKE_CXX_STANDARD 11)

# Visitor pattern
add_executable(lab7_tests
    ../src/unit_test.cpp
    ../src/binary_iterator.cpp
    ../src/preorder_iterator.cpp
    ../src/unary_iterator.cpp
)

add_executable(lab7
    ../src/main.cpp
    ../src/binary_iterator.cpp
    ../src/preorder_iterator.cpp
    ../src/unary_iterator.cpp
)

target_link_libraries(lab7_tests gtest)

target_compile_definitions(lab7_tests PRIVATE gtest_disable_pthreads=ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)