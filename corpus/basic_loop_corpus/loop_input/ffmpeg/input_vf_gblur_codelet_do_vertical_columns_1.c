#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define DATA_SIZE_MB 64

float *buffer;
int width = 1024;
int column_begin = 0;
int column_end;
int steps = 5;
float nu = 0.25f;
float boundaryscale = 2.0f;
int column_step = 8;
int numpixels;
int i;
int x;
int k;
int step;
float *ptr;

void init_vars() {
    size_t total_size = (size_t)(DATA_SIZE_MB * 1024 * 1024);
    numpixels = total_size / sizeof(float);
    
    column_end = width;
    if (column_end > numpixels) {
        column_end = numpixels;
    }
    
    buffer = (float*)aligned_alloc(32, numpixels * sizeof(float));
    if (!buffer) {
        exit(1);
    }
    
    for (int idx = 0; idx < numpixels; idx++) {
        buffer[idx] = (float)(idx % 256) * 0.1f;
    }
}