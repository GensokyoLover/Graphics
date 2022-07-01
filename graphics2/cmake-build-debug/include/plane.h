//
// Created by gensokyolover on 2022/6/17.
//

#ifndef GRAPHICS_PLANE_H
#define GRAPHICS_PLANE_H

#include <object3d.h>

class Plane:public Object3D{
public:
    Vec3f normal;
    float d;
    Plane(Vec3f &_n, float _d, Material *m):Object3D(m),normal(_n),d(_d){

    }
    virtual bool intersect(const Ray& r, Hit& h, float tmin){
        float t = -(-d + normal.Dot3(r.getOrigin())) / normal.Dot3(r.getDirection());
        if(t > tmin && t< h.getT()){
            h.set(t,this->materialPt,normal,r);
            return true;
        }
        return false;
    }
};

#endif //GRAPHICS_PLANE_H
