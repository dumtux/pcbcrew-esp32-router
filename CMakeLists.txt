cmake_minimum_required(VERSION 3.5)

set(EXTRA_COMPONENT_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/extra_components)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

add_definitions(-w)

add_compile_options("-DIP_PORTMAP_MAX=255")

string(REGEX REPLACE ".*/\(.*\)" "\\1" CURDIR ${CMAKE_CURRENT_SOURCE_DIR})
project(${CURDIR})

git_describe(PROJECT_VERSION ${COMPONENT_DIR})
message("Project commit: " ${PROJECT_VERSION})

spiffs_create_partition_image(spiffs ${CMAKE_CURRENT_SOURCE_DIR}/webapp/build FLASH_IN_PROJECT)
