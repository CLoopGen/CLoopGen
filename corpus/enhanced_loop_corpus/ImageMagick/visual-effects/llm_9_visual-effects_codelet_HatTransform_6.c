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
    // Variant 2: Reduced computational intensity with increased trip count and simplified computation
    for (; i < (ssize_t)(extent - scale / 2); i++) {
        if (scale >= 2) {
            kernel[i] = 0.5F * (*p + *(p + (scale / 2) * stride));
        } else {
            kernel[i] = *p;
        }
        p += (ptrdiff_t)stride;
    }
}
