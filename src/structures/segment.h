//
// Created by Aaron on 6/20/2022.
//

#ifndef OPENRAY_SEGMENT_H
#define OPENRAY_SEGMENT_H

#include <vector>
#include <string>

namespace openray {
    struct vec3 {
        float x {0};
        float y {0};
        float z {0};

        // Constructors
        vec3() = default;
        vec3(float x, float y, float z);
        vec3(const vec3 &other);

        // Functions
        [[nodiscard]] vec3 dot(const vec3 &other);
        [[nodiscard]] vec3 cross(const vec3 &other) const;
        [[nodiscard]] vec3 norm() const;

        // Operator overloads
        vec3 operator+ (const vec3 &other);
        vec3 operator* (int scalar) const;
        vec3 operator* (float scalar) const;
        friend std::ostream& operator<<(std::ostream &out, vec3 &v);

    };

    struct DirectionalVector {
        vec3 origin {0,0,0};
        vec3 endpoint {1,1,1};
    };

    struct Color {
        int r{0}, g{0}, b {0};

        Color() = default;
        Color(int r, int g, int b);

        // Functions
        void lighten(Color light_source_color);

        // Operator overloads
        Color operator+ (const Color &other);
        Color operator+ (int scalar);
        Color operator* (int scalar);
        Color operator* (float scalar);
    };

    struct Ray: DirectionalVector {
        int depth {0};
        const int MAX_DEPTH = {5};
    };
}


#endif //OPENRAY_SEGMENT_H
