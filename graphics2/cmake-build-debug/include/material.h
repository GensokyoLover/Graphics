//
// Created by gensokyolover on 2022/6/8.
//

#ifndef GRAPHICS_MATERIAL_H
#define GRAPHICS_MATERIAL_H
#include <vectors.h>
// ====================================================================
// ====================================================================

// You will extend this class in later assignments

class Material {

public:

    // CONSTRUCTORS & DESTRUCTOR
    Material(){

    }
    Material(const Vec3f &d_color) { diffuseColor = d_color; }
    virtual ~Material() {}

    // ACCESSORS
    virtual Vec3f getDiffuseColor() const { return diffuseColor; }

protected:

    // REPRESENTATION
    Vec3f diffuseColor;

};

// ====================================================================
// ====================================================================
#endif //GRAPHICS_MATERIAL_H
