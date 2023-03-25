cmake_minimum_required(VERSION 3.16)

project(MenuClass)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MenuClass_SOURCE_DIR}/bin)
message(STATUS "MenuClass Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create a library
############################################################

#Generate the shared library from the library sources

add_library(Menu_Lib SHARED
            include/M_Helper.hpp
            include/IMenuItem.hpp
            src/Menu_Item.cpp
            src/Menu.cpp
            )


add_library(menu::lib ALIAS Menu_Lib)

target_include_directories(Menu_Lib
                           PUBLIC
                           ${PROJECT_SOURCE_DIR}/include
                           )


############################################################
# Create an executable
############################################################

# Add an executable with the above sources

add_executable(Menu src/main.cpp)

# link the new hello_library target with the hello_binary target

target_link_libraries(Menu PRIVATE
                      menu::lib
                      )

# Tests
#add_subdirectory(tests)
