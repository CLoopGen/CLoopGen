#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 1024;
int height = 512;

float b0 = 0.4f;
float b1 = 0.3f;
float q = 0.2f;
float c = 0.1f;
float g;

float *dst;

void init_vars() {
    size_t total_size = (size_t)width * height * sizeof(float);
    dst = aligned_alloc(32, total_size);
    if (!dst) {
        exit(1);
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            dst[i * width + j] = (float)(i * width + j) * 0.001f;
        }
    }
    g = 0.0f;
}