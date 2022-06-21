//
// Created by Aaron on 6/20/2022.
//

#ifndef OPENRAY_SEGMENT_H
#define OPENRAY_SEGMENT_H

#import <vector>
namespace openray {
    struct vec3 {

        // Members
        std::vector<int> dim {0,0,0};
        int* x = dim.data();
        int* y = x + 1;
        int* z = x + 1;

        // Constructors
        vec3() = default;
        vec3(int x, int y, int z);
        vec3(const vec3 &other);

        // Functions
        vec3 dot(const vec3 &other);
        vec3 cross(const vec3 &other);

        // Operator overloads
        vec3 operator+ (const vec3 &other);
        vec3 operator* (const int scalar);
        vec3 operator* (const float scalar);

    };

    struct directional_vector {

    };
}


#endif //OPENRAY_SEGMENT_H
