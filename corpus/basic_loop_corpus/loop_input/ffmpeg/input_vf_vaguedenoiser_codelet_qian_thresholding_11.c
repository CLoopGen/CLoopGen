#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *block;
int width = 4096;
int height = 4096;
int stride = 4096;
float threshold = 1.5f;
float tr2 = 2.25f;
float frac = 0.8f;
int y;
int x;

void init_vars() {
    size_t total_size = (size_t)height * (size_t)stride * sizeof(float);
    block = (float*)aligned_alloc(32, total_size);
    for (size_t i = 0; i < total_size / sizeof(float); i++) {
        block[i] = (rand() % 2000 - 1000) / 100.0f;
    }
}