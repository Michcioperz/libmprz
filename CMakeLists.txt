cmake_minimum_required(VERSION 3.6)
project(libmprz VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES include/libmprz/stack.cpp include/libmprz/bell_utils.cpp include/libmprz/math.cpp)
set(HEADER_FILES include/libmprz/stack.h   include/libmprz/bell_utils.h   include/libmprz/math.h)

add_library(mprz SHARED ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(mprz PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")
install(TARGETS mprz
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)