cmake_minimum_required(VERSION 3.15)
project(ap4A VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Recursively collect all .cpp under src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)
if(NOT SOURCES)
  message(FATAL_ERROR "No source files found in ${CMAKE_SOURCE_DIR}/src")
endif()

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add sqlite_orm (header-only)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/sqlite_orm/include)

# Try to find sqlite3 (link library)
find_package(PkgConfig QUIET)
if(PKG_CONFIG_FOUND)
  pkg_check_modules(SQLITE3_PKG sqlite3)
  if(SQLITE3_PKG_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${SQLITE3_PKG_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SQLITE3_PKG_LIBRARIES})
  endif()
endif()

if(NOT SQLITE3_PKG_FOUND)
  find_library(SQLITE3_LIB NAMES sqlite3)
  if(SQLITE3_LIB)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SQLITE3_LIB})
  else()
    message(FATAL_ERROR "Could not find sqlite3 library. Install libsqlite3-dev (Debian/Ubuntu) or the sqlite3 dev package for your distro.")
  endif()
endif()

# Output directory
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Compiler warnings
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)

# Install
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
