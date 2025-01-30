cmake_minimum_required(VERSION 3.30)
project(koranteng)

set(CMAKE_CXX_STANDARD 20)

add_executable(koranteng main.cpp
        Sphere.cpp
        Sphere.h
        Light.cpp
        Light.h
        Camera.cpp
        Camera.h
        Ray.cpp
        Ray.h)

find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
target_link_libraries(koranteng PRIVATE sfml-system sfml-network sfml-graphics sfml-window sfml-audio)

find_package(glm CONFIG REQUIRED)
target_link_libraries(koranteng PRIVATE glm::glm)
