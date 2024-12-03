cmake_minimum_required(VERSION 3.5)
project(GUI VERSION 0.1 LANGUAGES CXX)

# Enable debug output for CMake
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Enforce C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add compile warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra)
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    scantypepage.cpp
    scantypepage.h
    scantypepage.ui
    schedulescanpage.h
    schedulescanpage.cpp
    schedulescanpage.ui
    historypage.h
    historypage.cpp
    historypage.ui
    quarantinepage.h
    quarantinepage.cpp
    quarantinepage.ui
    lastscanpage.h
    lastscanpage.cpp
    lastscanpage.ui
    settingspage.h
    settingspage.cpp
    settingspage.ui
    resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GUI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(GUI SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(GUI
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(GUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Add include directories
target_include_directories(GUI PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.GUI)
endif()

set_target_properties(GUI PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS GUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GUI)
endif()
