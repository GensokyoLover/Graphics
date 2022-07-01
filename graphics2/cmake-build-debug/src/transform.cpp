//
// Created by gensokyolover on 2022/7/1.
//
#include <transform.h>

bool Transform::intersect(const Ray &r, Hit &h, float tmin) {
    Vec4f newOrigin(r.getOrigin(), 1.0);
    Vec4f newDirection(r.getDirection(), 0.0);

    Matrix temp(mat);
    temp.Inverse(temp, 0.001);
    temp.Transform(newOrigin);
    temp.Transform(newOrigin);
    Vec3f newDirection3 = newDirection.ToVec3f();
    Vec3f newOrigin3 = newOrigin.ToVec3f();

    if (obj->intersect(Ray(newOrigin3, newDirection3), h, tmin))
    {
        // Make sure to correctly transform the resulting normal
        // according to the rule seen in lecture.
        Vec4f newNormal(h.getNormal(), 0.0);
        temp.Transpose();
        temp.Transform(newNormal);
        Vec3f m = newNormal.ToVec3f();
        m.Normalize();
        h.set(h.getT(), h.getMaterial(), m, r);
        return true;
    }
    return false
}