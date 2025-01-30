//
// Created by stepa on 30.01.2025.
//

#ifndef KORANTENG_LIGHT_H
#define KORANTENG_LIGHT_H


#include "SFML/Graphics/Color.hpp"
#include "glm/vec3.hpp"

class Light {
public:
    Light(const glm::vec3 &position, const sf::Color &color);

private:
    glm::vec3 position;
    sf::Color color;
};


#endif //KORANTENG_LIGHT_H
