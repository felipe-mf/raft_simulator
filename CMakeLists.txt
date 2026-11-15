cmake_minimum_required(VERSION 3.16)

project(raft_simulator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Liga AUTOMOC (classes com Q_OBJECT -> moc_*.cpp) e AUTOUIC (*.ui -> ui_*.h)
qt_standard_project_setup()

qt_add_executable(raft_simulator
    src/main.cpp
    src/gui/mainwindow.h
    src/gui/mainwindow.cpp
    src/gui/mainwindow.ui
)

# Includes relativos a src/, ex.: #include "gui/mainwindow.h"
target_include_directories(raft_simulator PRIVATE src)

target_link_libraries(raft_simulator PRIVATE Qt6::Widgets)

# No Windows, abre sem janela de console
set_target_properties(raft_simulator PROPERTIES WIN32_EXECUTABLE TRUE)
