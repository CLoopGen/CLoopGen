#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *buffer;
int width;
int height;
int steps;
float nu;
float bscale;
int step;
int x;
int y;
float *ptr;

void init_vars() {
    width = 4096;
    height = 256;
    steps = 5;
    nu = 0.1f;
    bscale = 0.95f;

    size_t buffer_size = (size_t)width * height * sizeof(float);
    buffer = (float*)aligned_alloc(32, buffer_size);
    
    for (size_t i = 0; i < width * height; i++) {
        buffer[i] = 1.0f + (i % 256) * 0.01f;
    }

    step = 0;
    x = 0;
    y = 0;
    ptr = buffer;
}