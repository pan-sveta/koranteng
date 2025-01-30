//
// Created by stepa on 30.01.2025.
//

#include "Scene.h"


void Scene::addObjects(std::unique_ptr<Object> object) {
    objects.push_back(std::move(object));
}



Scene::Scene(std::unique_ptr<Camera> camera) : camera(std::move(camera)) {

}

const std::unique_ptr<Camera> &Scene::getCamera() const {
    return camera;
}

const std::vector<std::unique_ptr<Object>> &Scene::getObjects() const {
    return objects;
}

