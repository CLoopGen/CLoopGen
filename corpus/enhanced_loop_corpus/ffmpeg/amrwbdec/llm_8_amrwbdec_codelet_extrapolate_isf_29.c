#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern float scale;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with more arithmetic operations and reduced trip count
    for (i = 17, j = 0; i < 19; i++, j++) {
        float diff = isf[i] - isf[i - 1];
        float diff_prev = (i > 1) ? isf[i - 1] - isf[i - 2] : 0.0f;
        float smoothed = 0.7f * diff + 0.3f * diff_prev;
        diff_isf[j] = scale * smoothed * (1.0f + 0.1f * j);
    }
}
