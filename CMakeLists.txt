cmake_minimum_required(VERSION 3.16)

project(raft_simulator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_library(raftcore STATIC
    src/core/logentry.h
    src/core/raftmessage.h
    src/core/raftnode.h
    src/core/raftnode.cpp
    src/core/simtime.h
)
target_include_directories(raftcore PUBLIC src)
target_link_libraries(raftcore PUBLIC Qt6::Core)

qt_add_executable(raft_simulator
    src/main.cpp
    src/gui/mainwindow.h
    src/gui/mainwindow.cpp
    src/gui/mainwindow.ui
)
target_include_directories(raft_simulator PRIVATE src)
target_link_libraries(raft_simulator PRIVATE raftcore Qt6::Widgets)

set_target_properties(raft_simulator PROPERTIES WIN32_EXECUTABLE TRUE)
