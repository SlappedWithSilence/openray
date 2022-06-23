//
// Created by Aaron on 6/20/2022.
//
#include <iostream>

#include "primitive.h"


bool Primitive::intersect(const openray::DirectionalVector &ray) const {
    std::cout << "[Error] Primitive::intersect called!" << std::endl;
    return false;
}

Primitive::Primitive(const openray::vec3 &origin, const openray::Color &surface_color,
                     const openray::Color &emission_color, float transparency, float reflectivity)
                     : origin(origin), surface_color(surface_color),
                     emission_color(emission_color), transparency(transparency),
                     reflectivity(reflectivity)
 {}

openray::DirectionalVector Primitive::normal(const openray::vec3 &surface_point) const {
    return {};
}
