cmake_minimum_required(VERSION 3.20)
project(Directory_Explorer)
set(CMAKE_CXX_STANDARD 23)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(PROJECT_SOURCES
        main.cpp
        report_generators.h
        report_generators.cpp
        handler.h
        handler.cpp)
find_package(Boost COMPONENTS system thread REQUIRED)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})
