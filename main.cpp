#include <iostream>
#include "src/scene/Camera.h"
#include "src/raytracer/Ray.h"
#include "SFML/Graphics/Color.hpp"
#include "src/objects/Sphere.h"
#include "src/scene/Scene.h"
#include "src/raytracer/RayTracer.h"

int main() {
    Camera camera(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f),
                  glm::vec3(1.0f, 0.0f, 0.0f), 1.f, 1.f, 1.f);

    Scene scene(std::make_unique<Camera>(camera));




    Material redMaterial;
    redMaterial.colour = glm::vec3(255,0,0);
    redMaterial.specularColour = glm::vec3(255,0,0);


    Material greenMaterial;
    greenMaterial.colour = glm::vec3(0,255,0);
    greenMaterial.specularColour = glm::vec3(0,255,0);

    Material blueMaterial;
    blueMaterial.colour = glm::vec3(0,0,255);
    blueMaterial.specularColour = glm::vec3(0,0,255);

    Sphere sphere(glm::vec3(0.f, -1.f, 3.f), 1.f, redMaterial);
    Sphere sphere2(glm::vec3(2.f, 0.f, 4.f), 1.f, blueMaterial);
    Sphere sphere3(glm::vec3(-2.f, 0.f, 4.f), 1.f, greenMaterial);

    scene.addObjects(std::make_unique<Sphere>(sphere));
    scene.addObjects(std::make_unique<Sphere>(sphere2));
    scene.addObjects(std::make_unique<Sphere>(sphere3));

    Material lightMaterial;
    lightMaterial.colour = glm::vec3(255,255,255);
    lightMaterial.emissionColour = glm::vec3(255,255,255);
    lightMaterial.emissionStrength = 4.f;

    Sphere lightSphere(glm::vec3(0.f, 3.f, 2.f), 1.f, lightMaterial);
    scene.addObjects(std::make_unique<Sphere>(lightSphere));

    RayTracer rayTracer;
    auto image = rayTracer.render(scene, 500, 500);

    image.saveToFile("../image.png");


    /*Sphere sphere(glm::vec3(0.f, -1.f, 3.f), 1.f, sf::Color(0, 255, 0));
    //Light light(glm::vec3(20.f,20.f,25.f), sf::Color(255,255,255));


    float canvasWidth = 1000.f;
    float canvasHeight = 1000.f;


    sf::Image image;
    image.create(canvasWidth + 1, canvasHeight + 1, sf::Color(0, 0, 0));

    for (auto x = -canvasWidth / 2; x <= canvasWidth / 2; x++) {
        for (auto y = -canvasHeight / 2; y <= canvasHeight / 2; y++) {
            glm::vec3 viewportPoint = camera.canvasToViewport(x, y, canvasWidth, canvasHeight);
            Ray ray(camera.getPosition(), glm::normalize(viewportPoint - camera.getPosition()));
            auto color = sphere.intersection(ray);


            image.setPixel(x + canvasWidth / 2, y + canvasHeight / 2, color);

        }
    }

    image.flipVertically();
    image.saveToFile("../image.png");*/


    return 0;

}
