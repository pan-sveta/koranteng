//
// Created by stepa on 30.01.2025.
//

#ifndef KORANTENG_SPHERE_H
#define KORANTENG_SPHERE_H

#include "Ray.h"
#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>


class Sphere {
public:
    Sphere(const glm::vec3 &position, float radius, const sf::Color &color);

    sf::Color interection(const Ray &ray) const;

private:
    glm::vec3 position;
    float radius;
    sf::Color color;


};


#endif //KORANTENG_SPHERE_H
