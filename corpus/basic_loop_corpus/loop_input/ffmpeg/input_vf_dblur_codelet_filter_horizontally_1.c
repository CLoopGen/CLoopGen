#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 1024;
int height = 512;

float b0 = 0.25f;
float b1 = 0.75f;
float q = 0.3f;
float c = 0.4f;
float g = 0.0f;

float *dst;

void init_vars() {
    size_t total_elements = (size_t)width * height;
    dst = (float*)aligned_alloc(32, total_elements * sizeof(float));
    if (!dst) {
        exit(1);
    }
    for (size_t i = 0; i < total_elements; i++) {
        dst[i] = (float)(i % 100) * 0.01f;
    }
}