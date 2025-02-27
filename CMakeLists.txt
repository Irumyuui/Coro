cmake_minimum_required(VERSION 3.21)

project(coro LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)

# set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_include_directories(${PROJECT_NAME} INTERFACE include/)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_23)

add_subdirectory(third_party/googletest)

# enable_testing()
# add_subdirectory(test/unittest)

enable_testing()
add_subdirectory(test)