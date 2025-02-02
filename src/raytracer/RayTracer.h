//
// Created by stepa on 30.01.2025.
//

#ifndef KORANTENG_RAYTRACER_H
#define KORANTENG_RAYTRACER_H


#include "../scene/Camera.h"
#include "SFML/Graphics/Image.hpp"
#include "../scene/Scene.h"

class RayTracer {
public:
    HitInfo calculateRayColission(Ray ray, const Scene& scene);
    glm::vec3 trace(Ray ray, const Scene& scene);
    sf::Image render(const Scene &scene, int width, int height);
};


#endif //KORANTENG_RAYTRACER_H
