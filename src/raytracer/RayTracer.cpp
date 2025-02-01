//
// Created by stepa on 30.01.2025.
//

#include "RayTracer.h"
#include "glm/glm.hpp"

sf::Image RayTracer::render(const Scene &scene, int width, int height) {
    sf::Image image;
    image.create(width + 1, height + 1, sf::Color(255, 255, 255));

    const float minT = scene.getCamera()->getDistance();
    const float maxT = std::numeric_limits<float>::max();

    for (auto x = -width / 2; x <= width / 2; x++) {
        for (auto y = -height / 2; y <= height / 2; y++) {
            glm::vec3 viewportPoint = scene.getCamera()->canvasToViewport(x, y, width, height);
            Ray ray(scene.getCamera()->getPosition(), glm::normalize(viewportPoint - scene.getCamera()->getPosition()));

            const Object* closestObject = nullptr;
            HitInfo closestHitInfo(false,FLT_MAX,glm::vec3(0,0,0),glm::vec3(0,0,0));

            for (const auto& obj : scene.getObjects()) {
                auto hitInfo = obj->intersection(ray);
                if (hitInfo.isHit && hitInfo.distance < closestHitInfo.distance) {
                    closestHitInfo = hitInfo;
                    closestObject = obj.get();
                }
            }

            if (closestObject != nullptr) {
                image.setPixel(x + width / 2, y + height / 2, closestObject->material.colour);
            }

        }
    }

    image.flipVertically();
    return image;
}
