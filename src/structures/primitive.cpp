//
// Created by Aaron on 6/20/2022.
//
#include <iostream>

#include "primitive.h"


bool Primitive::intersect(const openray::DirectionalVector &ray) const {
    std::cout << "[Error] Primitive::intersect called!" << std::endl;
    return false;
}

openray::DirectionalVector Primitive::normal(const openray::vec3 &surface_point) const {
    return openray::DirectionalVector();
}
