
cmake_minimum_required(VERSION 3.20.0)


project(error 
  HOMEPAGE_URL https://github.com/meanbot/error
  DESCRIPTION "error - error codes & categories" 
  VERSION 0.0.1 
  LANGUAGES CXX)

include(cmake/CPM.cmake)

CPMAddPackage(
  NAME xxhashct 
  GITHUB_REPOSITORY ekpyron/xxhashct 
  GIT_TAG "master" 
  DOWNLOAD_ONLY YES
)

add_library(${PROJECT_NAME} STATIC 
   
  src/precomp.cpp 
)

add_library(meanbot::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_compile_options(${PROJECT_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${xxhashct_SOURCE_DIR}")

target_precompile_headers(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/precomp.hpp")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
