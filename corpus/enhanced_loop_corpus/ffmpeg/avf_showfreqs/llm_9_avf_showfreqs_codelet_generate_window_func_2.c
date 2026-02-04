#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    float center = (N - 1) / 2.0f;
    float inv_center = (N > 1) ? 1.0f / center : 0.0f;
    for (i = 0; i < N; i++) {
        float diff = (i - center) * inv_center;
        float term = diff * diff;
        lut[i] = 1.0f - term * term; // Higher computational intensity: quartic instead of quadratic
    }
}
