cmake_minimum_required(VERSION 3.10)
project(CustomClamAVScanner CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(SQLite3 REQUIRED)
find_package(OpenSSL REQUIRED)  # ClamAV dependency

# Source files
set(SOURCES
    src/main.cpp
    src/Database.cpp
    src/scheduler.cpp
    src/quickscan.cpp
    src/systemscan.cpp
    src/customscan.cpp
)

# Header files directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Create executable
add_executable(clamav-scanner ${SOURCES})

# Find ClamAV
find_package(PkgConfig REQUIRED)
pkg_check_modules(CLAMAV REQUIRED libclamav)

# Include directories
target_include_directories(clamav-scanner PRIVATE
    ${SQLite3_INCLUDE_DIRS}
    ${CLAMAV_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(clamav-scanner
    PRIVATE
    ${SQLite3_LIBRARIES}
    ${CLAMAV_LIBRARIES}
    stdc++fs
)

# Installation
install(TARGETS clamav-scanner
    RUNTIME DESTINATION bin
)