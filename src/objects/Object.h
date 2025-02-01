//
// Created by stepa on 30.01.2025.
//
#ifndef KORANTENG_OBJECT_H
#define KORANTENG_OBJECT_H

#include <tuple>

#include "Material.h"
#include "../raytracer/HitInfo.h"
#include "glm/vec3.hpp"
#include "SFML/Graphics/Color.hpp"
#include "../raytracer/Ray.h"

class Object {
public:
    Object(const glm::vec3 &position, Material material) : position(position), material(material) {}

    virtual HitInfo intersection(const Ray &ray) const = 0;

    glm::vec3 getPosition() const {
        return position;
    }

    Material material;

protected:
    glm::vec3 position;
};


#endif //KORANTENG_OBJECT_H