#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *gauss_kernel;
extern float length;
extern float gauss_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float running_factor = 1.0f;
    float inv_gauss_sum = 1.0f / gauss_sum;
    for (int i = 0; i < length; ++i) {
        gauss_kernel[i] *= inv_gauss_sum;
        running_factor *= inv_gauss_sum; // Introduce artificial loop-carried WAW dependency
    }
    // Use running_factor to prevent dead code elimination
    if (running_factor < 0.0f) {
        gauss_kernel[0] = running_factor;
    }
}
