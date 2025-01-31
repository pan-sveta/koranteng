//
// Created by stepa on 30.01.2025.
//

#include <iostream>
#include "Sphere.h"
#include "glm/geometric.hpp"


std::tuple<float, float> Sphere::intersection(const Ray &ray) const {
    glm::vec3 oc = ray.O - position;
    float a = glm::dot(ray.D, ray.D);
    float b = 2.0f * glm::dot(oc, ray.D);
    float c = glm::dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;

    //Return t values
    return std::make_tuple((-b - sqrt(discriminant)) / (2.0f * a), (-b + sqrt(discriminant)) / (2.0f * a));
}

Sphere::Sphere(glm::vec3 position, float radius, sf::Color color) : radius(radius), Object(position, color) {}




