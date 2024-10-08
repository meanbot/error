
cmake_minimum_required(VERSION 3.20.0)


project(error_tests 
  HOMEPAGE_URL https://github.com/meanbot/error 
  DESCRIPTION "error - error codes & categories - tests" 
  VERSION 0.0.1 
  LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/CPM.cmake)

CPMAddPackage("gh:fmtlib/fmt#10.1.1")

CPMAddPackage( 
  NAME meanbot_error 
  SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.."
)

add_executable(${PROJECT_NAME} 
  error_tests.cpp 
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

target_link_libraries(${PROJECT_NAME} fmt::fmt-header-only)
target_link_libraries(${PROJECT_NAME} meanbot::error)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
