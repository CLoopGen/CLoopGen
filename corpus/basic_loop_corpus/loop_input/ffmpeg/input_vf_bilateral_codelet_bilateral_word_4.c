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
    width = 16384;
    h1 = 5;
    
    size_t total_size = (h1 + 1) * width;
    size_t ypy_size = width;

    img_out_f = (float*)aligned_alloc(32, total_size * sizeof(float));
    map_factor_b = (float*)aligned_alloc(32, total_size * sizeof(float));
    ypy = (float*)aligned_alloc(32, ypy_size * sizeof(float));

    for (size_t i = 0; i < total_size; i++) {
        img_out_f[i] = (float)(i % 100) / 10.0f;
        map_factor_b[i] = (float)(i % 50) / 5.0f + 1.0f;
    }
    for (size_t i = 0; i < ypy_size; i++) {
        ypy[i] = (float)((i + 10) % 90) / 10.0f;
    }
}