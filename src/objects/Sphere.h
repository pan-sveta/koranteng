//
// Created by stepa on 30.01.2025.
//

#ifndef KORANTENG_SPHERE_H
#define KORANTENG_SPHERE_H

#include "Object.h"


class Sphere: public Object {
public:

    Sphere(glm::vec3 position, float radius, sf::Color color);

    std::tuple<float, float> intersection(const Ray &ray) const override;

private:
    float radius;
};


#endif //KORANTENG_SPHERE_H
