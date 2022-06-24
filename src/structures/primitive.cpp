//
// Created by Aaron on 6/20/2022.
//
#include <iostream>
#include <cmath>
#include <vector>

#include "primitive.h"


bool Primitive::intersect(const openray::Ray &ray, std::vector<float> &intersection_lengths) const {
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

bool Sphere::intersect(const openray::Ray &ray, std::vector<float> &intersection_lengths) const {
    openray::vec3 L = origin - ray.origin; // Vector from ray origin to sphere origin

    float tc = L.dot(ray.direction); // Length multiplier for ray direction

    if (tc < 0) return false; // sphere is behind ray

    float d2 = tc*tc - L.length2(); // length from sphere origin to ray
    float radius2 = radius * radius;
    if (d2 > radius2) return false;

    float t1c = std::sqrt(radius2 - d2);
    float t1 = tc - t1c; // First intersection
    float t2 = tc + t1c; // Second intersection
    intersection_lengths.push_back(t1);
    intersection_lengths.push_back(t2);

    return true;
}

Sphere::Sphere(const openray::vec3 &origin, float radius, const openray::Color &surface_color,
               const openray::Color &emission_color, float transparency, float reflectivity)
               : Primitive(origin, surface_color, emission_color, transparency, reflectivity), radius(radius)
               {}
