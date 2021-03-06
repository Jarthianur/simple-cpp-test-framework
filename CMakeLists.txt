cmake_minimum_required(VERSION 3.7.2)
project(TestPlusPlus LANGUAGES CXX)

if (NOT DEFINED TPP_PROJECT_SELF)
  set(TPP_PROJECT_SELF OFF)
  if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(TPP_PROJECT_SELF ON)
    message(STATUS "TestPlusPlus is itself the project")
  endif ()
endif ()

option(TPP_INTERNAL "Generate internal project targets" ${TPP_PROJECT_SELF})

add_library(tpp INTERFACE)
target_include_directories(tpp INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

if(TPP_INTERNAL)
  if(NOT "${CMAKE_CXX_STANDARD}")
    set(CMAKE_CXX_STANDARD 11)
  endif()
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
  set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
  set(CMAKE_BUILD_TYPE staged)
  set(CMAKE_CXX_FLAGS_STAGED "-Wall -Wextra -Wpedantic -Werror -Wnon-virtual-dtor -Wno-unused-function -Wno-unknown-pragmas -O0 -g")

  file(GLOB_RECURSE sources ${PROJECT_SOURCE_DIR}/test/*.cpp)

  add_executable(test_seq ${sources})
  target_compile_options(test_seq PUBLIC --coverage)
  target_link_libraries(test_seq PUBLIC gcov tpp)

  add_executable(test_par ${sources})
  target_compile_options(test_par PUBLIC -fopenmp --coverage)
  target_link_libraries(test_par PUBLIC gcov gomp tpp)

  add_executable(rel_test_seq ${sources})
  target_compile_options(rel_test_seq PUBLIC --coverage)
  target_include_directories(rel_test_seq PUBLIC ${PROJECT_SOURCE_DIR}/release)
  target_link_libraries(rel_test_seq PUBLIC gcov)

  add_executable(rel_test_par ${sources})
  target_compile_options(rel_test_par PUBLIC -fopenmp --coverage)
  target_include_directories(rel_test_par PUBLIC ${PROJECT_SOURCE_DIR}/release)
  target_link_libraries(rel_test_par PUBLIC gcov gomp)

  add_executable(compiledb_dummy ${sources})
  target_compile_options(compiledb_dummy PUBLIC -fopenmp)
  target_link_libraries(compiledb_dummy PUBLIC gomp tpp)

  if("${GENERATE_COMPILEDB}")
    if(NOT "${COMPILEDB_TARGET}")
      set(COMPILEDB_TARGET compiledb_dummy)
    endif()
    execute_process(COMMAND compiledb --command-style -n make -C ${CMAKE_BINARY_DIR} ${COMPILEDB_TARGET})
  endif()
endif()
