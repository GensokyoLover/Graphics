//
// Created by gensokyolover on 2022/6/10.
//

#ifndef GRAPHICS_GROUP_H
#define GRAPHICS_GROUP_H
#include <matrix.h>
#include <vectors.h>
#include <material.h>
#include <hit.h>
#include <ray.h>
#include <vector>
#include <object.h>



class Group:public Object3D{
public:
    int num;
    vector<Object3D*> objVec;
    Group(){

    }
    Group(int _n):num(_n){
        objVec.resize(num);
    }

    void addObject(int index, Object3D *obj){
        objVec[index] = obj;
    }

    virtual bool intersect(const Ray &r, Hit &h, float min){
        for(int i = 0; i < num; i++){

            objVec[i]->intersect(r, h, min);
        }
        return true;
    }
};

#endif //GRAPHICS_GROUP_H
