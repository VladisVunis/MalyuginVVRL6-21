cmake_minimum_required(VERSION 3.16)

project(SW_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SW_1 main.cpp
    sorts.h
    sorts.cpp)

include(GNUInstallDirs)
install(TARGETS SW_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
