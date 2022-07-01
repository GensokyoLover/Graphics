//
// Created by gensokyolover on 2022/7/1.
//

#ifndef GRAPHICS_TRANSFORM_H
#define GRAPHICS_TRANSFORM_H
#include <object3d.h>

class Transform : public Object3D{
public:
    Matrix mat;
    Object3D* obj;
    Transform(Matrix& m, Object3D* o):obj(o),mat(m){

    }
    ~Transform();
    virtual bool intersect(const Ray& r, Hit& h, float tmin);

};
#endif //GRAPHICS_TRANSFORM_H
