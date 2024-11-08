cmake_minimum_required(VERSION 3.20)
project(quantum_nexus)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

include_directories(include)

add_executable(quantum_nexus
        src/main.cpp
        src/player.cpp
        src/game.cpp)

target_link_libraries(quantum_nexus PRIVATE sfml-graphics sfml-window sfml-system)