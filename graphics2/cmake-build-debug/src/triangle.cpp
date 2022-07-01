//
// Created by gensokyolover on 2022/7/1.
//
#include <triangle.h>

struct Matrix3x3f{
    Vec3f v[3];
};

float cal_determinan(Matrix3x3f m){
    float sum = 0;
    for(int i = 0; i < 3; i++){
        sum += m.v[0][i] * m.v[1][(i+1)%3] * m.v[2][(i+2)%3];
    }
    for(int i = 0; i < 3; i++){
        sum -= m.v[0][i] * m.v[1][(i+2)%3] * m.v[2][(i+1)%3];
    }
    return sum;
}

bool Triangle::intersect(const Ray& r, Hit& h, float tmin){ //克莱姆法则
    Matrix3x3f A;
    A.v[0].Set(v[0].x() - v[1].x(), v[0].y() - v[1].y(), v[0].z() - v[1].z());
    A.v[1].Set(v[0].x()-v[2].x(),v[0].y()-v[2].y(),v[0].z()-v[2].z());
    A.v[2].Set(r.getDirection().x(),r.getDirection().y(),r.getDirection().z());
    Vec3f d(v[0].x()-r.getOrigin().x(),v[0].y()-r.getOrigin().y(),v[0].z()-r.getOrigin().z());
    float t,interpolation[3];
    float di = cal_determinan(A);
    for(int i = 0; i < 3; i++){
        Matrix3x3f now = A;
        now.v[i] = d;
        float up = cal_determinan(now);
        switch(i){
            case 0:
                interpolation[1] = up/di;
                break;
            case 1:
                interpolation[2] = up/di;
                break;
            case 2:
                t = up/di;
                break;
        }
        interpolation[0] = 1 - interpolation[1] - interpolation[2];
        if(t > tmin && h.getT() && interpolation[0] > 0 && interpolation[1] > 0 && interpolation[2] > 0){
            Vec3f e0 = v[1] - v[0];
            Vec3f e1 = v[2] - v[1];
            h.set(t,materialPt,normal,r);
            return true;
        }
        return false;
    }
}