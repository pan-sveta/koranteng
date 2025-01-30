//
// Created by stepa on 30.01.2025.
//

#include "Camera.h"

Camera::Camera(const glm::vec3 &position, const glm::vec3 &direction, const glm::vec3 &up, const glm::vec3 &right,
               float distance, float viewportWidth, float viewportHeight) : position(position), direction(direction),
                                                                            up(up), right(right), distance(distance),
                                                                            viewportWidth(viewportWidth),
                                                                            viewportHeight(viewportHeight) {}

glm::vec3 Camera::canvasToViewport(float x, float y, float canvasWidth, float canvasHeight) const {
    float scaleX = viewportWidth / canvasWidth;
    float scaleY = viewportHeight / canvasHeight;

    glm::vec3 viewportPoint(x*(scaleX), y*(scaleY), distance);

    return viewportPoint;
}

glm::vec3 Camera::getPosition() const {
    return position;
}

