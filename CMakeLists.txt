cmake_minimum_required(VERSION 3.4...3.28 FATAL_ERROR)

project(PONG-GLFW VERSION 0.1.0 LANGUAGES C HOMEPAGE_URL "https://github.com/b3r8t3r/Pong-GLFW")

set(CMAKE_C_STANDARD 99)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# ===============
# GLFW
# ===============

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)

FetchContent_MakeAvailable(
        glfw
)

find_package(OpenGL REQUIRED)

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

# ===============
# Libraries
# ===============

# ---------------
# Types
# ---------------

add_library(TYPES STATIC src/types.c)

target_include_directories(TYPES PUBLIC ${CMAKE_SOURCE_DIR}/include)

# ---------------
# Square
# ---------------

add_library(SQUARE STATIC src/square_lib.c)

target_include_directories(SQUARE
    PUBLIC 
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(SQUARE PRIVATE OpenGL::GL glfw)

# ===============
# Tests
# ===============

option(PONG_BUILD_TESTS "Build the Pong tests" TRUE)

if (PONG_BUILD_TESTS)
#        add_executable(TESTS-CONSOLE WIN32 tests/tests.c)
#        target_include_directories(TESTS-CONSOLE PRIVATE ${CMAKE_SOURCE_DIR}/include)
#        target_link_libraries(TESTS-CONSOLE PRIVATE TYPES)
        add_subdirectory(tests)
endif()

# ===============
# Application
# ===============
add_executable(PONG-GLFW WIN32 src/main.c)

target_include_directories(PONG-GLFW PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(PONG-GLFW PRIVATE SQUARE OpenGL::GL glfw)

if (MSVC)
    # Tell MSVC to use main instead of WinMain
    set_target_properties(PONG-GLFW PROPERTIES
                          LINK_FLAGS "/ENTRY:mainCRTStartup")
elseif (CMAKE_C_SIMULATE_ID STREQUAL "MSVC")
    # Tell Clang using MS CRT to use main instead of WinMain
    set_target_properties(PONG-GLFW PROPERTIES
                          LINK_FLAGS "-Wl,/entry:mainCRTStartup")
endif()