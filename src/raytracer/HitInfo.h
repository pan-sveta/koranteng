//
// Created by Filip on 02.02.2025.
//

#ifndef HITINFO_H
#define HITINFO_H
#include <glm/glm.hpp>

struct HitInfo
{
    bool isHit;
    float distance;
    glm::vec3 hitpoint;
    glm::vec3 normal;
    Material material;
};

#endif //HITINFO_H
