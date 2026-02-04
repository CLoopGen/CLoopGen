#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float inv_scale = (N > 1) ? 2.0 / (N - 1) : 1.0;
    float temp_sum = 0.0;
    for (n = 0; n < N; n++) {
        float normalized = (n - (N - 1)/2.0) * inv_scale;
        float squared = normalized * normalized;
        lut[n] = 1.0 - squared;
        temp_sum += lut[n];  // Introduce intra-loop dependency (WAW-like via temp_sum, though not loop-carried in value)
    }
    // Dummy use of temp_sum to prevent elimination (maintains data dependency)
    if (temp_sum < 0) lut[0] = 0.0;
}
