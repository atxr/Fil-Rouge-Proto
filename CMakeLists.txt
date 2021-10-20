cmake_minimum_required(VERSION 3.16)

project(
  proto
  VERSION
  1.0
  LANGUAGES
  CXX
)

# Find SFML shared libraries
find_package(SFML 2.5 
  COMPONENTS 
    system window graphics network audio REQUIRED
  )

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(app ${SRC_FILES})
target_include_directories(app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${SFML_INCLUDE_DIR})
target_link_libraries(app sfml-graphics sfml-window)

