#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define DATA_SIZE_MB 64

float *block = NULL;
int width;
int height;
int stride;
float threshold;
float frac;
int y;
int x;

void init_vars() {
    const size_t total_elements = (size_t)DATA_SIZE_MB * 1024 * 1024 / sizeof(float);
    
    width = 4096;
    height = total_elements / width;
    if (height == 0) height = 1;
    while ((size_t)width * height > total_elements) {
        height--;
    }
    
    stride = width + 16; 
    
    float *data = (float*)aligned_alloc(32, sizeof(float) * stride * height);
    if (!data) exit(1);
    
    block = data;
    
    threshold = 10.0f;
    frac = 0.5f;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            data[i * stride + j] = (float)((rand() % 2000) - 1000) / 100.0f;
        }
    }
}