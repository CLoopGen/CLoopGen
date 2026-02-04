#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t stride;
size_t scale;

float *kernel;
float *restrict p;
float *restrict q;
float *restrict r;

ssize_t i;

void init_vars() {
    scale = 64 * 1024 * 1024; 
    stride = 1;

    kernel = (float*)aligned_alloc(32, scale * sizeof(float));
    float* base_p = (float*)aligned_alloc(32, (scale + 1) * stride * sizeof(float));
    float* base_q = (float*)aligned_alloc(32, (scale + 1) * stride * sizeof(float));
    float* base_r = (float*)aligned_alloc(32, (scale + 1) * stride * sizeof(float));

    p = base_p;
    q = base_q + scale * stride;
    r = base_r;

    for (size_t idx = 0; idx < (scale + 1) * stride; idx++) {
        base_p[idx] = 1.0f;
        base_q[idx] = 2.0f;
        base_r[idx] = 3.0f;
    }

    for (size_t idx = 0; idx < scale; idx++) {
        kernel[idx] = 0.0f;
    }
}