//
// Created by Filip on 02.02.2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H
#include <glm/vec3.hpp>
#include <SFML/Graphics/Color.hpp>

struct Material {
  glm::vec3 colour{};
  glm::vec3 emissionColour{};
  glm::vec3 specularColour{};
  float emissionStrength{};
  float smoothness{};
  float specularProbability{};
};
#endif //MATERIAL_H
