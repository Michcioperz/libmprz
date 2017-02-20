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
set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_TEST_NAME} mprz GTest::GTest GTest::Main gcov)
get_target_property(TEMP ${PROJECT_TEST_NAME} COMPILE_FLAGS)
if(TEMP STREQUAL "TEMP-NOTFOUND")
    set(TEMP "")
else()
    set(TEMP "${TEMP} ")
endif()
set(TEMP "${TEMP}-fprofile-arcs -ftest-coverage")
set_target_properties(${PROJECT_TEST_NAME} PROPERTIES COMPILE_FLAGS ${TEMP})
add_test(gtest ${PROJECT_TEST_NAME})
