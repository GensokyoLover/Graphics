//
// Created by gensokyolover on 2022/6/17.
//

#ifndef GRAPHICS_TRIANGLE_H
#define GRAPHICS_TRIANGLE_H

#include <object3d.h>



class Triangle:public Object3D{
public:
    vector<Vec3f> v;
    Vec3f normal;
    Triangle(const Vec3f &a,const Vec3f &b,const Vec3f &c, Material *m):Object3D(m),v{a,b,c}{
        normal = (b - a).Cross(c - b);
    }
    virtual bool intersect(const Ray& r, Hit& h, float tmin);
};

#endif //GRAPHICS_TRIANGLE_H
