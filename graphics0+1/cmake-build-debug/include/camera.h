//
// Created by gensokyolover on 2022/6/9.
//

#ifndef GRAPHICS_CAMERA_H
#define GRAPHICS_CAMERA_H

#include <matrix.h>
#include <vectors.h>
#include <ray.h>
class Camera{
public:
    Camera() {
    }
    virtual ~Camera(){}
    virtual Ray generateRay(Vec2f point) = 0;
    virtual float getTMin() const = 0;
};


#endif //GRAPHICS_CAMERA_H
