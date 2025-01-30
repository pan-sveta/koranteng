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
            float closestT = std::numeric_limits<float>::max();

            for (const auto& obj : scene.getObjects()) {
                auto [t0, t1] = obj->interection(ray);
                if (t0 > minT && t0 < maxT && t0 < closestT) {
                    closestT = t0;
                    closestObject = obj.get();
                }
            }

            if (closestObject != nullptr) {
                image.setPixel(x + width / 2, y + height / 2, closestObject->getColor());
            }

        }
    }

    image.flipVertically();
    return image;
}
