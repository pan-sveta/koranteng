//
// Created by stepa on 30.01.2025.
//

#include <iostream>
#include "Sphere.h"


Sphere::Sphere(const glm::vec3 &position, float radius, const sf::Color &color) : position(position), radius(radius),
                                                                                     color(color) {}

sf::Color Sphere::interection(const Ray &ray) const {
    glm::vec3 oc = ray.O - position;
    float a = glm::dot(ray.D, ray.D);
    float b = 2.0f * glm::dot(oc, ray.D);
    float c = glm::dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;

    //Output t values

    if(discriminant < 0){
        return sf::Color(0,0,0);
    }
    else{
        return color;
    }
}
