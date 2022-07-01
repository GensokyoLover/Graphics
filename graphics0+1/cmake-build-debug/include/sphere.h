//
// Created by gensokyolover on 2022/6/10.
//

#ifndef GRAPHICS_SPHERE_H
#define GRAPHICS_SPHERE_H
#include <matrix.h>
#include <vectors.h>
#include <material.h>
#include <hit.h>
#include <ray.h>
#include <vector>
#include <object.h>
class Sphere:public Object3D{
public:
    float radius;
    Vec3f center;
    Sphere(Vec3f _center, float _radius, Material* _m): Object3D(_m), radius(_radius), center(_center){

    }
    Sphere() {

    }
    virtual bool intersect(const Ray &r, Hit &h, float tmin) {
        float a = 1;
        Vec3f ro = r.getOrigin() - center;
        float b = 2 * r.getDirection().Dot3(ro);
        float c = ro.Dot3(ro) - radius * radius;
        Vec3f f(1,1,10);;
        Vec3f q = r.getOrigin();
        if(q.x() > 1 && q.y() > 1 && q.x()<1.3 && q.y() <1.3 ) {
            cout<<q<<endl;
            cout<<r.getOrigin()<<endl;
            cout<<r.getDirection()<<endl;
            cout<<center<<" "<<radius<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        if (b * b >= 4 * a * c){

            float d = sqrt(b * b - 4 * a * c);
            float t1 = (-b - d) / 2 * a;
            Vec3f f(1,1,10);;
            Vec3f q = r.getOrigin();
            if(q.x() > 1 && q.y() > 1 ) {
                cout<<q<<endl;
                cout<<t1<<endl;
            }
            if (t1 > tmin && t1 < h.getT()) {
                h.set(t1, materialPt, r);
            }
        }
        return true;
    }
};

#endif //GRAPHICS_SPHERE_H
