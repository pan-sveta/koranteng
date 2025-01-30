cmake_minimum_required(VERSION 3.30)
project(koranteng)

set(CMAKE_CXX_STANDARD 20)

add_executable(koranteng main.cpp
        src/objects/Sphere.cpp
        src/objects/Sphere.h
        src/objects/Light.cpp
        src/objects/Light.h
        src/scene/Camera.cpp
        src/scene/Camera.h
        src/raytracer/Ray.cpp
        src/raytracer/Ray.h
        src/scene/Scene.cpp
        src/scene/Scene.h
        src/objects/Object.h
        src/raytracer/RayTracer.cpp
        src/raytracer/RayTracer.h)

find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
target_link_libraries(koranteng PRIVATE sfml-system sfml-network sfml-graphics sfml-window sfml-audio)

find_package(glm CONFIG REQUIRED)
target_link_libraries(koranteng PRIVATE glm::glm)
