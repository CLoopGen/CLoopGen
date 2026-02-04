#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float base = (N - 1) / 2.;
    float inv_base_sq = 1.0f / (base * base);
    float temp_sum = 0.0f;
    for (n = 0; n < N; n++) {
        float diff = n - base;
        float sq_diff = diff * diff;
        lut[n] = 1.0f - sq_diff * inv_base_sq;
        temp_sum += lut[n]; // Introduce intra-loop dependency (WAW-like via temp_sum, though not carried)
    }
    // Use temp_sum to prevent loop optimization that removes it (ensure side-effect)
    if (temp_sum < 0) lut[0] = temp_sum;
}
