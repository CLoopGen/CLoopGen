#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *gauss_kernel;
float length;
float gauss_sum;

void init_vars() {
    length = 16777216; // ~16.7M elements to target ~0.01 sec runtime
    gauss_sum = 1234.567f;
    gauss_kernel = (float*)aligned_alloc(32, (size_t)length * sizeof(float));
    for (int i = 0; i < length; ++i) {
        gauss_kernel[i] = (float)(i % 1000) + 0.5f;
    }
}