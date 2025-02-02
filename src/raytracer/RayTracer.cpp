//
// Created by stepa on 30.01.2025.
//

#include "RayTracer.h"

#include <iostream>
#include <ostream>

#include "glm/glm.hpp"

HitInfo RayTracer::calculateRayColission(Ray ray, const Scene& scene)
{
    HitInfo closestHitInfo(false,FLT_MAX);

    for (const auto& obj : scene.getObjects())
    {
        auto hitInfo = obj->intersection(ray);
        if (hitInfo.isHit && hitInfo.distance < closestHitInfo.distance)
        {
            closestHitInfo = hitInfo;
        }
    }

    return closestHitInfo;
}

float RandomValueNormalDistribution()
{
    // Thanks to https://stackoverflow.com/a/6178290
    float theta = 2 * 3.1415926 * (rand()/RAND_MAX);
    float rho = sqrt(-2 * log(rand()/RAND_MAX));
    return rho * cos(theta);
}

// Calculate a random direction
glm::vec3 RandomDirection()
{
    // Thanks to https://math.stackexchange.com/a/1585996
    float x = RandomValueNormalDistribution();
    float y = RandomValueNormalDistribution();
    float z = RandomValueNormalDistribution();
    return glm::normalize(glm::vec3(x, y, z));
}

glm::vec3 lerp(const glm::vec3& start, const glm::vec3& end, float t) {
    return start + t * (end - start);  // Perform linear interpolation
}

glm::vec3 RayTracer::trace(Ray ray, const Scene& scene)
{
    glm::vec3 incomingLight(0,0,0);
    glm::vec3 rayColour(0,0,0);

    const int MaxBounceCount = 7;

    for (int bounceIndex = 0; bounceIndex <= MaxBounceCount; bounceIndex ++)
    {
        HitInfo hitInfo = calculateRayColission(ray,scene);

        if (hitInfo.isHit)
        {
            Material material = hitInfo.material;

            // Figure out new ray position and direction
            //bool isSpecularBounce = material.specularProbability >= (rand() / RAND_MAX);
            bool isSpecularBounce = false;

            ray.O = hitInfo.hitpoint;
            glm::vec3 diffuseDir = glm::normalize(hitInfo.normal + RandomDirection());
            glm::vec3 specularDir = reflect(ray.D, hitInfo.normal);
            ray.D = glm::normalize(lerp(diffuseDir, specularDir, material.smoothness * isSpecularBounce));

            // Update light calculations
            glm::vec3 emittedLight = material.emissionColour * material.emissionStrength;
            incomingLight += emittedLight * rayColour;
            rayColour *= lerp(material.colour, material.specularColour, isSpecularBounce);

            // Random early exit if ray colour is nearly 0 (can't contribute much to final result)
            float p = std::max(rayColour.r, std::max(rayColour.g, rayColour.b));
            if ((rand()/RAND_MAX) >= p) {
                break;
            }
            rayColour *= 1.0f / p;
        }
        /*else
        {
            incomingLight += GetEnvironmentLight(ray) * rayColour;
            break;
        }*/
    }

    return incomingLight;
}

sf::Image RayTracer::render(const Scene& scene, int width, int height)
{
    sf::Image image;
    image.create(width + 1, height + 1, sf::Color(255, 255, 255));


    for (auto x = -width / 2; x <= width / 2; x++)
    {
        for (auto y = -height / 2; y <= height / 2; y++)
        {
            glm::vec3 viewportPoint = scene.getCamera()->canvasToViewport(x, y, width, height);

            constexpr int raysPerPixel = 7;
            glm::vec3 totalIncomingLight(0, 0, 0);

            for (int rayIndex = 0; rayIndex < raysPerPixel; rayIndex++)
            {
                Ray ray(scene.getCamera()->getPosition(),
                        glm::normalize(viewportPoint - scene.getCamera()->getPosition()));

                totalIncomingLight += trace(ray, scene);
                std::cout << "Total Light r: " << totalIncomingLight.r << "g: " << totalIncomingLight.g << "b: " << totalIncomingLight.b << std::endl;
            }

            sf::Color pixelColor(totalIncomingLight.r / raysPerPixel, totalIncomingLight.g / raysPerPixel,
                                 totalIncomingLight.b / raysPerPixel);


            image.setPixel(x + width / 2, y + height / 2, pixelColor);
        }
    }

    image.flipVertically();
    return image;
}
