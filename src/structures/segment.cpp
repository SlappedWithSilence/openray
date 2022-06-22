//
// Created by Aaron on 6/20/2022.
//

#include "segment.h"
#include "math/fast_math.h"

#include <ostream>

/*** vec3 definitions ***/
openray::vec3::vec3(float x, float y, float z)
    : x(x), y(y), z(z)
{}

openray::vec3::vec3(const openray::vec3 &other)
    : x(other.x), y(other.y), z(other.z)
{}

// Vector dot product
openray::vec3 openray::vec3::dot(const openray::vec3 &other) {
    float dot_x = x * other.x;
    float dot_y = y * other.y;
    float dot_z = z * other.z;
    return {dot_x, dot_y, dot_z};
}

// Vector cross product
// Returns a vector with a 90-degree angle to both composite vectors (unit vector)
openray::vec3 openray::vec3::cross(const openray::vec3 &other) const {
    float cross_x = y * other.z - z * other.y;
    float cross_y = z * other.x - x * other.z;
    float cross_z = x * other.y - y * other.x;
    return {cross_x, cross_y, cross_z};
}

// Add two vec3's together
openray::vec3 openray::vec3::operator+(const openray::vec3 &other) {
    return {x + other.x, y+other.y, z+other.z};
}

// Scale a vec3 by 'scalar'
openray::vec3 openray::vec3::operator*(const int scalar) const {
    return {x * (float) scalar,
            y * (float) scalar,
            z * (float) scalar
            };
}

// Scale a vec3 by 'scalar'
openray::vec3 openray::vec3::operator*(const float scalar) const {
    return {x * scalar,
            y * scalar,
            z * scalar
            };
}

// Return a normalized vector
openray::vec3 openray::vec3::norm() const {
    float divisor = openray::inverse_sqrt(x*x + y*y +z*z); // Calculate the divisor using an approximation
    return {x * divisor,
            y * divisor,
            z * divisor
            };
}

std::ostream &openray::operator<<(std::ostream &out, openray::vec3 &v) {
    out << "<" << v.x << ", " << v.y << ", " << v.z << ">";
    return out;
}

bool openray::vec3::operator==(const openray::vec3 &other) const {
    if (this == &other) {
        return true;
    }
    return (x == other.x) && (y == other.y) && (z == other.z);
}

openray::vec3 openray::vec3::operator-(const openray::vec3 &other) {
    return {x-other.x, y - other.y, z - other.z};
}

/*** Color Definitions ***/
openray::Color::Color(int r, int g, int b)
    : r(r), g(g), b(b)
{}

// Sum current color channels with argument's color values
void openray::Color::lighten(openray::Color light_source_color) {
    r += light_source_color.r;
    g += light_source_color.g;
    b += light_source_color.b;
}

// Returns a Color vector with summed channel values
openray::Color openray::Color::operator+(const openray::Color &other) const {
    return {r + other.r, g + other.g, b + other.b};
}

// Returns a Color vector offset by 'offset'
openray::Color openray::Color::operator+(int offset) const {
    return {r + offset, g + offset, b + offset};
}

// Returns a color vector scaled by 'scalar'. Integer arithmetic
openray::Color openray::Color::operator*(int scalar) const {
    return {(r * scalar), (g * scalar), (b * scalar)};
}

// Return a color vector scaled by 'scalar'. Float arithmetic cast to an int.
openray::Color openray::Color::operator*(float scalar) const {
    return {(int)((float) r * scalar), (int)((float) g * scalar), (int)((float) b * scalar)};
}

openray::Color openray::Color::operator-(const openray::Color &other) const {
    return {r - other.r, g - other.g, b - other.b};
}

openray::Color openray::Color::operator-(int scalar) const {
    return {r - scalar, g - scalar, b - scalar};
}
