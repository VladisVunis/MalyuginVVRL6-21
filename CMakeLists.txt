cmake_minimum_required(VERSION 3.16)

project(SW2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SW2 main.cpp
    bit_operations.h
    bit_operations.cpp
    file_operations.h
    file_operations.cpp
    box.h
    box.cpp
    sorts.h
    sorts.cpp
    fraction.h
    fraction.cpp
    ring_buffer.cpp
    ring_buffer.h
    filo.cpp
    filo.h
    task_filo.h
    task_filo.cpp
    test.cpp
    test.h
    task_filo.cpp
    task_filo.h
    test_ring_buffer.h
    test_ring_buffer.cpp



)
include(GNUInstallDirs)
install(TARGETS SW2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

#test
