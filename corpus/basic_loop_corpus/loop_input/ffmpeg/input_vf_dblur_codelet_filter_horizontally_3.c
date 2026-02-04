#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 1024;
int height = 1024;

float b0 = 0.25f;
float b1 = 0.50f;
float q = 0.75f;
float c = 0.10f;
float g = 0.0f;

float *dst;

void init_vars() {
    size_t num_elements = (size_t)width * (size_t)height;
    dst = (float*)aligned_alloc(32, num_elements * sizeof(float));
    if (!dst) {
        exit(1);
    }
    for (size_t i = 0; i < num_elements; i++) {
        dst[i] = (float)(i % 100) / 100.0f;
    }
}