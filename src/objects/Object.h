//
// Created by stepa on 30.01.2025.
//
#ifndef KORANTENG_OBJECT_H
#define KORANTENG_OBJECT_H

#include <tuple>
#include "glm/vec3.hpp"
#include "SFML/Graphics/Color.hpp"
#include "../raytracer/Ray.h"

class Object {
public:
    Object(const glm::vec3 &position, const sf::Color &color) : position(position), color(color) {}

    virtual std::tuple<float, float> interection(const Ray &ray) const = 0;

    glm::vec3 getPosition() const {
        return position;
    }

    sf::Color getColor() const {
        return color;
    }

protected:
    glm::vec3 position;
    sf::Color color;
};


#endif //KORANTENG_OBJECT_H