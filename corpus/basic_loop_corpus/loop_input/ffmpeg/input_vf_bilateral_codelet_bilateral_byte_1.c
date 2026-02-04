#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
float *img_out_f;
float *map_factor_b;
float *ypy;
int h1;

void init_vars() {
    width = 8192;
    h1 = 10;

    size_t total_size = width * (h1 + 1);
    img_out_f = (float*)aligned_alloc(32, total_size * sizeof(float));
    map_factor_b = (float*)aligned_alloc(32, total_size * sizeof(float));
    ypy = (float*)aligned_alloc(32, width * sizeof(float));

    for (size_t i = 0; i < total_size; i++) {
        img_out_f[i] = (float)(i % 100) + 1.0f;
        map_factor_b[i] = (float)(i % 50) + 1.0f;
    }
    for (int x = 0; x < width; x++) {
        ypy[x] = (float)((x * 2) % 100) + 0.5f;
    }
}