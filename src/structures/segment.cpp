//
// Created by Aaron on 6/20/2022.
//

#include "segment.h"

/* vec3 definitions */
openray::vec3::vec3(int x, int y, int z)
    :dim({x, y, z})
{}


openray::vec3::vec3(const openray::vec3 &other)
    : dim(other.dim)
{}

// Vector dot product
openray::vec3 openray::vec3::dot(const openray::vec3 &other) {
    int dot_x = *(this->x) * *(other.x);
    int dot_y = *(this->y) * *(other.y);
    int dot_z = *(this->z) * *(other.z);
    return {dot_x, dot_y, dot_z};
}

// Vector cross product
// Returns a vector with a 90-degree angle to both composite vectors (unit vector)
openray::vec3 openray::vec3::cross(const openray::vec3 &other) {
    int cross_x = *(this->y) * *(other.z) - *(this->z) * *(other.y);
    int cross_y = *(this->z) * *(other.x) - *(this->x) * *(other.z);
    int cross_z = *(this->x) * *(other.y) - *(this->y) * *(other.x);
    return {cross_x, cross_y, cross_z};
}

// Add two vec3's together
openray::vec3 openray::vec3::operator+(const openray::vec3 &other) {
    return {};
}

// Scale a vec3 by 'scalar'
openray::vec3 openray::vec3::operator*(const int scalar) {
    return openray::vec3({*(this->x) * scalar,
                          *(this->y) * scalar,
                          *(this->z) * scalar}
                          );
}

// Scale a vec3 by 'scalar'
openray::vec3 openray::vec3::operator*(const float scalar) {
    return openray::vec3({static_cast<int>(*(this->x) * scalar),
                          static_cast<int>(*(this->y) * scalar),
                          static_cast<int>(*(this->z) * scalar)}
    );
}
