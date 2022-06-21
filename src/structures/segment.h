//
// Created by Aaron on 6/20/2022.
//

#ifndef OPENRAY_SEGMENT_H
#define OPENRAY_SEGMENT_H

#include <vector>
namespace openray {
    struct vec3 {

        // Members
        std::vector<float> dim {0,0,0};
        float* x = dim.data();
        float* y = x + 1;
        float* z = x + 1;

        // Constructors
        vec3() = default;
        vec3(float x, float y, float z);
        vec3(const vec3 &other);

        // Functions
        vec3 dot(const vec3 &other);
        vec3 cross(const vec3 &other);
        vec3 norm();

        // Operator overloads
        vec3 operator+ (const vec3 &other);
        vec3 operator* (int scalar);
        vec3 operator* (float scalar);

    };

    struct directional_vector {
        vec3 origin {0,0,0};
        vec3 endpoint {1,1,1};
    };
}


#endif //OPENRAY_SEGMENT_H
