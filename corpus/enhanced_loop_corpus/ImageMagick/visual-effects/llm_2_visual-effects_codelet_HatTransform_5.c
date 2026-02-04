#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t stride;
extern  size_t scale;
extern float *kernel;
extern  float *restrict p;
extern  float *restrict q;
extern  float *restrict r;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset indexing
    // Instead of striding through p, q, r with pointer arithmetic,
    // use base pointers and calculate indices to access consecutive elements.
    float *base_p = p;
    float *base_q = q;
    float *base_r = r;
    for (i = 0; i < (ssize_t)scale; i++) {
        size_t idx = i * stride;
        kernel[i] = 0.25F * (base_p[idx] + base_p[idx] + base_q[-idx] + base_r[idx]);
    }
}
