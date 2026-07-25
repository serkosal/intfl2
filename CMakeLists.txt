cmake_minimum_required(VERSION 4.0)

# Set experimental flag to enable `import std` support from CMake.
# This must be enabled before C++ language support.
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD
  # This specific value changes as experimental support evolves. See
  # `Help/dev/experimental.rst` in the CMake source corresponding to
  # your CMake build for the exact value to use.
  "d0edc3af-4c50-42ea-a356-e2862fe7a444"
)

project(intfl2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_MODULE_STD ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

# MODULES SUPPORT
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# FTXUI
set(FTXUI_BUILD_MODULES ON)

include(FetchContent)
 
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG v7.0.1  # Replace with a version, tag, or commit hash
)
 
FetchContent_MakeAvailable(ftxui)

# my modules
add_library(app_component)
target_sources(app_component
  PUBLIC FILE_SET CXX_MODULES FILES
    src/appComponent.cpp
)
target_link_libraries(app_component
  PRIVATE ftxui::modules
)

add_library(button_component)
target_sources(button_component
  PUBLIC FILE_SET CXX_MODULES FILES
    src/buttonComponent.cpp
)
target_link_libraries(button_component
  PRIVATE ftxui::modules
)

# executable

add_executable(intfl2 src/main.cpp)
target_link_libraries(intfl2
  PRIVATE app_component
  PRIVATE button_component
)