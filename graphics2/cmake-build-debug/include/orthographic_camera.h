//
// Created by gensokyolover on 2022/6/10.
//

#ifndef GRAPHICS_ORTHOGRAPHIC_CAMERA_H
#define GRAPHICS_ORTHOGRAPHIC_CAMERA_H

#include <matrix.h>
#include <vectors.h>
#include <ray.h>
#include <camera.h>
class OrthographicCamera:public Camera{
public:
    Vec3f dir,center,up,horizontal;
    float size;

    OrthographicCamera(Vec3f _center, Vec3f _dir, Vec3f _up, float _size):center(_center),dir(_dir),up(_up),size(_size){
        dir.Normalize();
        up = up - dir.Dot3(up) * dir;
        Vec3f::Cross3(horizontal,dir,up);
    }

    virtual Ray generateRay(Vec2f point){
        Vec3f src = center + horizontal * (point.x() * 2 * size - size) + up * (point.y() * 2 * size -size) ;
        Ray ray(src, dir);
        return ray;
    }
    virtual float getTMin() const {
        return -1e9;
    }
};

#endif //GRAPHICS_ORTHOGRAPHIC_CAMERA_H
