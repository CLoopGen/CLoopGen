#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t stride;
extern  size_t extent;
extern  size_t scale;
extern float *kernel;
extern  float *restrict p;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    for (; i < (ssize_t)(extent - 2 * scale); i++) {
        float val_center = *p;
        float val_prev = *(p - scale * stride);
        float val_next = *(p + scale * stride);
        float val_prev2 = *(p - 2 * scale * stride);
        float val_next2 = *(p + 2 * scale * stride);
        kernel[i] = 0.1F * (3.F * val_center + val_prev + val_next + 0.5F * (val_prev2 + val_next2));
        p += (ptrdiff_t)stride;
    }
}
