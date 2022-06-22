//
// Created by Aaron on 6/20/2022.
//

#ifndef OPENRAY_PRIMITIVE_H
#define OPENRAY_PRIMITIVE_H

#include "segment.h"

// Base class for all shapes
struct Primitive {
    openray::vec3 origin {0,0,0};
    openray::Color surface_color {128,128,128}, emission_color {30,30,30};
    float transparency, reflectivity = 0;

    // Functions
    [[nodiscard]] virtual bool intersect(const openray::DirectionalVector &ray) const;
    [[nodiscard]] virtual openray::DirectionalVector normal(const openray::vec3 &surface_point) const;
};

struct Sphere : Primitive {

};

struct Cube : Primitive {

};

struct Pyramid : Primitive {

};

struct Cylinder : Primitive {

};

struct Plane : Primitive {

};


#endif //OPENRAY_PRIMITIVE_H
