#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float period;
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int len;
extern int i;
extern int j;
extern int center;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled inner loop and reduced trip count
    int step = width < 4 ? 1 : 2; // Increase step to reduce outer loop iterations
    for (i = 1; i < ((((len) >= 0 ? (len) + ((width) >> 1) : (len) - ((width) >> 1)) / (width)) + step - 1) / step; i += step) {
        center = (int)(i * period + 0.5);
        // Unroll inner loop by factor of 2 if width allows
        int start = -width / 2;
        int end = (width + 1) / 2;
        for (j = start; j < end - 1; j += 2) {
            speech[j + center] += ppc_gain * (*shape++);
            speech[j + 1 + center] += ppc_gain * (*shape++);
        }
        // Handle remaining iteration if needed
        if (j == end - 1) {
            speech[j + center] += ppc_gain * (*shape++);
        }
    }
}
