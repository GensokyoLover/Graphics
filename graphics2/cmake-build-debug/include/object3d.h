//
// Created by gensokyolover on 2022/6/8.
//

#ifndef GRAPHICS_OBJECT3D_H
#define GRAPHICS_OBJECT3D_H
#include <matrix.h>
#include <vectors.h>
#include <material.h>
#include <hit.h>
#include <ray.h>
#include <vector>
class Object3D{
public:
    Material* materialPt;
    Object3D(){}
    Object3D(Material* _m){
        materialPt = _m;
    }
    virtual bool intersect(const Ray& r, Hit& h, float tmin) =0;
};



#endif //GRAPHICS_OBJECT3D_H
