//
// Created by stepa on 30.01.2025.
//

#ifndef KORANTENG_RAYTRACER_H
#define KORANTENG_RAYTRACER_H


#include <random>
#include "../scene/Camera.h"
#include "SFML/Graphics/Image.hpp"
#include "../scene/Scene.h"

class RayTracer {

public:
    RayTracer();

    HitInfo calculateRayColission(Ray ray, const Scene& scene);
    glm::vec3 trace(Ray ray, const Scene& scene);
    sf::Image render(const Scene &scene, int width, int height);

protected:
    std::mt19937 gen;
    std::uniform_real_distribution<float> dist;
    std::normal_distribution<float> normalDistribution;

    float RandomValue();

    float RandomValueNormalDistribution();

    glm::vec3 RandomDirection();
};


#endif //KORANTENG_RAYTRACER_H
