#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 4096;
int height = 64;

float b0 = 1.1f;
float b1 = 0.9f;
float q = 0.25f;
float c = 0.75f;
float g;

float *dst;

void init_vars() {
    size_t total_elements = (size_t)height * width;
    dst = (float*)aligned_alloc(32, total_elements * sizeof(float));
    if (!dst) {
        exit(1);
    }

    for (size_t i = 0; i < total_elements; i++) {
        dst[i] = (float)(i % 100) / 100.0f;
    }
}