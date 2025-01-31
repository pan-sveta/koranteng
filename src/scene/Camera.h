//
// Created by stepa on 30.01.2025.
//

#ifndef KORANTENG_CAMERA_H
#define KORANTENG_CAMERA_H


#include "glm/vec3.hpp"

class Camera {
public:
    Camera(const glm::vec3 &position, const glm::vec3 &direction, const glm::vec3 &up, const glm::vec3 &right,
           float distance, float viewportWidth, float viewportHeight);

    //Canvas to Viewport Transformation
    glm::vec3 canvasToViewport(int x, int y, int canvasWidth, int canvasHeight) const;

    glm::vec3 getPosition() const;

    [[nodiscard]] float getDistance() const;

private:
    glm::vec3 position;
    glm::vec3 direction;
    glm::vec3 up;
    glm::vec3 right;
    float distance;
    float viewportWidth;
    float viewportHeight;

};


#endif //KORANTENG_CAMERA_H
