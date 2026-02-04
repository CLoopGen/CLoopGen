#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
float *map_factor_b;
float *ypf;
int h1;

void init_vars() {
    width = 8192;
    h1 = 10;
    size_t array_size = (h1 + 1) * width * sizeof(float);
    map_factor_b = (float*)aligned_alloc(32, array_size);
    ypf = (float*)aligned_alloc(32, width * sizeof(float));
    for (size_t i = 0; i < (h1 + 1) * width; i++) {
        map_factor_b[i] = (float)(i % 100) / 10.0f;
    }
    for (size_t i = 0; i < width; i++) {
        ypf[i] = (float)((i + 1) % 75) / 5.0f;
    }
}