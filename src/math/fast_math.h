//
// Created by Aaron on 6/20/2022.
//

#ifndef OPENRAY_FAST_MATH_H
#define OPENRAY_FAST_MATH_H

namespace openray {

    // Fast inverse square root, of Quake III fame.
    // Small original modifications.
    float inverse_sqrt(float number, int iterations = 1) {
        const float three_halfs = 1.5F;

        float x2 = number * 0.5F;
        float y = number;

        // evil floating point bit level hacking
        long i = *(long*) &y;

        // value is pre-assumed
        i = 0x5f3759df - (i >> 1);
        y = * (float* ) &i;

        // Each iteration increases approximation's accuracy
        for (int j = 0; j < iterations; j++) {
            y = y * (three_halfs - (x2 * y * y));
        }

        return y;
    }

} // openray

#endif //OPENRAY_FAST_MATH_H
