//
// Created by Aaron on 6/20/2022.
//

#include "segment.h"
#include "math/fast_math.h"

/* vec3 definitions */
openray::vec3::vec3(float x, float y, float z)
    :dim({x, y, z})
{}


openray::vec3::vec3(const openray::vec3 &other)
    : dim(other.dim)
{}

// Vector dot product
openray::vec3 openray::vec3::dot(const openray::vec3 &other) {
    float dot_x = *(this->x) * *(other.x);
    float dot_y = *(this->y) * *(other.y);
    float dot_z = *(this->z) * *(other.z);
    return {dot_x, dot_y, dot_z};
}

// Vector cross product
// Returns a vector with a 90-degree angle to both composite vectors (unit vector)
openray::vec3 openray::vec3::cross(const openray::vec3 &other) {
    float cross_x = *(this->y) * *(other.z) - *(this->z) * *(other.y);
    float cross_y = *(this->z) * *(other.x) - *(this->x) * *(other.z);
    float cross_z = *(this->x) * *(other.y) - *(this->y) * *(other.x);
    return {cross_x, cross_y, cross_z};
}

// Add two vec3's together
openray::vec3 openray::vec3::operator+(const openray::vec3 &other) {
    return {};
}

// Scale a vec3 by 'scalar'
openray::vec3 openray::vec3::operator*(const int scalar) {
    return openray::vec3({*(this->x) * (float) scalar,
                          *(this->y) * (float) scalar,
                          *(this->z) * (float) scalar
                            }
                          );
}

// Scale a vec3 by 'scalar'
openray::vec3 openray::vec3::operator*(const float scalar) {
    return openray::vec3({(*(this->x) * scalar),
                          (*(this->y) * scalar),
                          (*(this->z) * scalar)}
    );
}

openray::vec3 openray::vec3::norm() {
    float divisor = openray::inverse_sqrt(*(this->x) * *(this->x) +
                                                 *(this->y) * *(this->y) +
                                                 *(this->z) * *(this->z)
                                                 );
    return {(*(this->x) * divisor),
            (*(this->y) * divisor),
            (*(this->z) * divisor)
            };
}
