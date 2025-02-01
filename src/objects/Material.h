//
// Created by Filip on 02.02.2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H
#include <SFML/Graphics/Color.hpp>

struct Material {
  sf::Color colour;
  sf::Color emissionColour;
  sf::Color specularColour;
  sf::Color emissionStrength;
  float smoothness{};
  float specularProbability{};
};
#endif //MATERIAL_H
