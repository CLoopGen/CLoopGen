#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t stride;
extern  size_t extent;
extern float *kernel;
extern  float *restrict p;
extern  float *restrict q;
extern  float *restrict r;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access, process elements in a unit-stride (consecutive) manner
    // This improves cache locality by accessing adjacent memory locations.
    float *p_base = p;
    float *q_base = q;
    float *r_base = r;
    for (; i < (ssize_t)extent; i++) {
        size_t offset = i * stride;
        kernel[i] = 0.25F * (p_base[offset] + p_base[offset] + q_base[offset] + r_base[offset]);
    }
}
