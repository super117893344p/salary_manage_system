cmake_minimum_required(VERSION 3.26)
project(salary_manage_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(salary_manage_system main.cpp
        employee.cpp
        employee.h
        salary_management.cpp
        salary_management.h
        worker.cpp
        worker.h
)
