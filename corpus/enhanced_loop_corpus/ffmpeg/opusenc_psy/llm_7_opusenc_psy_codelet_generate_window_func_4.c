#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float center = (N - 1) / 2.0;
    float inv_scale_sq = 4.0 / ((N - 1) * (N - 1));
    float temp_sum = 0.0;
    for (n = 0; n < N; n++) {
        float diff = n - center;
        temp_sum += diff; // Introduce artificial loop-carried dependency (WAW via temp_sum)
        lut[n] = 1.0 - diff * diff * inv_scale_sq;
    }
    // Ensure temp_sum is used to prevent dead code elimination
    if (temp_sum != temp_sum) { // volatile-like use (noop but preserves dependency)
        lut[0] = 0.0;
    }
}
