cmake_minimum_required(VERSION 3.11)
project(act_map LANGUAGES CXX)

add_library(act_map INTERFACE IMPORTED GLOBAL)
set(include_directories ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(act_map PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${include_directories}"
)

add_subdirectory(thirdparty)
add_subdirectory(test)