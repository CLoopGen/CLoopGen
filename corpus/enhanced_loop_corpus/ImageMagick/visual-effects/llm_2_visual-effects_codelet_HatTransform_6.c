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
    // Variant 1: Consecutive Memory Access (unrolled with stride precomputed)
    ssize_t scaled_stride = scale * stride;
    float *p_base = p;
    for (; i < (ssize_t)(extent - scale); i++) {
        kernel[i] = 0.25F * (2.F * p_base[0] + p_base[-scaled_stride] + p_base[scaled_stride]);
        p_base += stride;
    }
}
