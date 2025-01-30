#include <iostream>
#include "Sphere.h"
#include "Light.h"
#include "Camera.h"

int main() {

    Sphere sphere(glm::vec3(0.f, -1.f, 3.f), 1.f, sf::Color(0, 255, 0));
    //Light light(glm::vec3(20.f,20.f,25.f), sf::Color(255,255,255));
    Camera camera(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f),
                  glm::vec3(1.0f, 0.0f, 0.0f), 1.f, 1.f, 1.f);

    float canvasWidth = 1000.f;
    float canvasHeight = 1000.f;


    sf::Image image;
    image.create(canvasWidth + 1, canvasHeight + 1, sf::Color(0, 0, 0));

    for (auto x = -canvasWidth / 2; x <= canvasWidth / 2; x++) {
        for (auto y = -canvasHeight / 2; y <= canvasHeight / 2; y++) {
            glm::vec3 viewportPoint = camera.canvasToViewport(x, y, canvasWidth, canvasHeight);
            Ray ray(camera.getPosition(), glm::normalize(viewportPoint - camera.getPosition()));
            auto color = sphere.interection(ray);


            image.setPixel(x + canvasWidth / 2, y + canvasHeight / 2, color);

        }
    }

    image.saveToFile("image.png");


    return 0;

}
