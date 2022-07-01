//
// Created by gensokyolover on 2022/6/17.
//

#ifndef GRAPHICS_PERSPECTIVECAMERA_H
#define GRAPHICS_PERSPECTIVECAMERA_H

#include <camera.h>

class  PerspectiveCamera{
public:
    Vec3f center;
    Vec3f dir;
    Vec3f up;
    Vec3f horizontal;
    float angle;
    PerspectiveCamera() = default;
    PerspectiveCamera(Vec3f& _center, Vec3f &_dir, Vec3f &_up, float _angle):center(_center),dir(_dir),up(_up),angle(_angle){
        dir.Normalize();
        up.Normalize();
        up = up - dir.Dot3(up) * dir;
        Vec3f::Cross3(horizontal,dir,up);
    }
    virtual ~PerspectiveCamera(){}
    virtual Ray generateRay(Vec2f point){
        Vec3f temp = dir + 2 * tan(angle / 2) * up * (point.x() - 0.5) + 2 * tan(angle / 2) * horizontal *(point.y() - 0.5);
        return Ray(center, temp);
    }
    virtual float getTMin() const = 0;
};

#endif //GRAPHICS_PERSPECTIVECAMERA_H
