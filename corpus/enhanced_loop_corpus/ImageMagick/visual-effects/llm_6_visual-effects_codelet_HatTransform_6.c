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
    float prev_val = 0.0F;
    for (; i < (ssize_t)(extent - scale); i++) {
        float current = (*p);
        kernel[i] = 0.25F * (2.F * current + *(p - scale * stride) + *(p + scale * stride)) + prev_val;
        prev_val = current;
        p += (ptrdiff_t)stride;
    }
}
