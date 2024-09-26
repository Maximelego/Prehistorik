cmake_minimum_required(VERSION 3.10)

project(Prehistoric LANGUAGES C)

set(HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/2headers")
set(CODEFILES "${CMAKE_CURRENT_SOURCE_DIR}/1codeFiles")

file(GLOB SOURCES
    "${HEADERS}/*.h"
    "${CODEFILES}/*.c"
)

# Needed so that cmake uses our find modules.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/SDL)

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Mixer SDL2::Image SDL2::TTF)



# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
  set(DOXYGEN_GENERATE_HTML YES)

  doxygen_add_docs(
    doxygen
    ${PROJECT_SOURCE_DIR}
)
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
