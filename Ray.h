//
// Created by stepa on 30.01.2025.
//

#ifndef KORANTENG_RAY_H
#define KORANTENG_RAY_H


#include "glm/vec3.hpp"

struct Ray {
public:
    Ray(const glm::vec3 &origin, const glm::vec3 &direction);

    glm::vec3 O;
    glm::vec3 D;
};


#endif //KORANTENG_RAY_H
