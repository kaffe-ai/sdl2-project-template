cmake_minimum_required(VERSION 3.10)

# Project Name
project(SDL2_project_template C)

# Set C Standard
set(CMAKE_C_STANDARD 99)

if(WIN32 AND WSL)
    # SDL2 setup for Windows Subsystem for Linux (WSL)
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
    set(SDL2_LIBRARIES ${SDL2_LIBRARIES})
elseif(APPLE)
    # SDL2 setup for macOS
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
    set(SDL2_LIBRARIES ${SDL2_LIBRARIES})
elseif(UNIX)
    # SDL2 setup for Linux (on WSL or native)
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
    set(SDL2_LIBRARIES ${SDL2_LIBRARIES})
endif()

# Source Files
file(GLOB SOURCES src/*.c)

# Add the include/ dir globally
include_directories(${CMAKE_SOURCE_DIR}/include)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SDL2
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

# Post-Build: Copy SDL2.dll (Windows only, if running WSL or native)
if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${SDL2_RUNTIME_LIBS} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()
