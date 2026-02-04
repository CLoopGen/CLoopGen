#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_taps;
extern float scale;
extern int dc_norm;
extern int i;
extern float *h;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sum = sum;
    float inv_sum = 1.0f / temp_sum;
    float adjusted_scale = scale * inv_sum;
    float running_product = 1.0f;
    for (i = 0; dc_norm && i < num_taps; i++) {
        running_product *= h[i]; // Introduce WAW and loop-carried dependency via running_product
        h[i] = h[i] * adjusted_scale;
    }
    // Use running_product to preserve data dependency and prevent dead code elimination
    if (running_product == 0.0f) {
        h[0] = 0.0f;
    }
}
