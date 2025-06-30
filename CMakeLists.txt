# Uuh random version cuz idk all the differences between CMake implementations
cmake_minimum_required(VERSION 3.20)

# Define our project !!1!!1§!1!
project(SDLShenanigans)

# Find SDL3 packages
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_mixer REQUIRED)
find_package(glm REQUIRED)


# Add executable & sources
add_executable(SDLShenanigans main.cpp)
add_subdirectory(src)

# As well as header files
target_include_directories(SDLShenanigans PRIVATE ${PROJECT_SOURCE_DIR}/include)

# And link libraries !
target_link_libraries(SDLShenanigans PRIVATE  SDL3::SDL3 SDL3_image::SDL3_image SDL3_mixer::SDL3_mixer glm::glm)

# Copy assets into build directory
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})