cmake_minimum_required(VERSION 3.6)
project(libmprz VERSION 0.3.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES include/mprz/stack.cpp include/mprz/bell_utils.cpp include/mprz/math.cpp)
set(HEADER_FILES include/mprz/stack.h include/mprz/bell_utils.h include/mprz/math.h)

add_library(mprz SHARED ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(mprz PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")
install(TARGETS mprz
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include/mprz)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_TEST_NAME} mprz GTest::GTest GTest::Main)
add_test(gtest ${PROJECT_TEST_NAME})