//
// Created by stepa on 30.01.2025.
//

#include <iostream>
#include "Sphere.h"
#include "glm/geometric.hpp"


HitInfo Sphere::intersection(const Ray &ray) const {
    HitInfo hitInfo(false,0.F,glm::vec3(0,0,0), glm::vec3(0,0,0), this->material);

    glm::vec3 oc = ray.O - position;
    float a = glm::dot(ray.D, ray.D);
    float b = 2.0f * glm::dot(oc, ray.D);
    float c = glm::dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        float dst = (-b - sqrt(discriminant)) / (2 * a);
        if (dst > 0.0f)
        {
            hitInfo.isHit = true;
            hitInfo.distance = dst;
            hitInfo.hitpoint = ray.O + dst * ray.D;
            hitInfo.normal = glm::normalize(hitInfo.hitpoint - this->position);
        }
    }

    return hitInfo;
}

Sphere::Sphere(glm::vec3 position, float radius, Material material) : radius(radius), Object(position, material) {}




