//
// Created by stepa on 30.01.2025.
//

#ifndef KORANTENG_SCENE_H
#define KORANTENG_SCENE_H


#include <vector>
#include <memory>
#include "../objects/Object.h"
#include "Camera.h"

class Scene {
public:
    Scene(std::unique_ptr<Camera> camera);

    void addObjects(std::unique_ptr<Object> object);
    const std::vector<std::unique_ptr<Object>> & getObjects() const;
    const std::unique_ptr<Camera>& getCamera() const;
private:
    std::unique_ptr<Camera> camera;
    std::vector<std::unique_ptr<Object>> objects;
};


#endif //KORANTENG_SCENE_H
