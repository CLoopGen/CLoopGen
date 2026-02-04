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
    for (; i < (ssize_t)(extent - scale); i++) {
        float center = *p;
        float left = (i > 0) ? *(p - scale * stride) : center;
        float right = *(p + scale * stride);
        kernel[i] = 0.25F * (2.F * center + left + right);
        p += (ptrdiff_t)stride;
    }
}
