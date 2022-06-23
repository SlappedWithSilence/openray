//
// Created by Aaron on 6/20/2022.
//
#include <iostream>

#include "primitive.h"


bool Primitive::intersect(const openray::Ray &ray) const {
    std::cout << "[Error] Primitive::intersect called!" << std::endl;
    return false;
}

Primitive::Primitive(const openray::vec3 &origin, const openray::Color &surface_color,
                     const openray::Color &emission_color, float transparency, float reflectivity)
                     : origin(origin), surface_color(surface_color),
                     emission_color(emission_color), transparency(transparency),
                     reflectivity(reflectivity)
 {}

openray::Ray Primitive::normal(const openray::vec3 &surface_point) const {
    return {};
}

bool Sphere::intersect(const openray::Ray &ray) const {
    float dist = ray.origin.dot(origin);

    // If the sphere is in front of the ray
    if (dist > 0) {
        openray::vec3 ray_orig_to_sphere_orig = origin - ray.origin;
    }
    return false;
}
