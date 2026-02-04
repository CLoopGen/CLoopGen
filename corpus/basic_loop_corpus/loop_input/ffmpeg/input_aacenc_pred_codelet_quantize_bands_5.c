#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int *out;
float *in;
float *scaled;
int size;
int is_signed;
int maxval;
float Q34;
float rounding;
int i;

void init_vars() {
    // Set data size to achieve approximately 0.01 seconds runtime
    // Assuming moderate CPU speed and ~10-20 cycles per iteration, aim for ~10M elements
    size = 10000000;  // 10 million elements

    // Allocate arrays
    in = (float*)aligned_alloc(32, size * sizeof(float));
    scaled = (float*)aligned_alloc(32, size * sizeof(float));
    out = (int*)aligned_alloc(32, size * sizeof(int));

    // Initialize scalar variables
    is_signed = 1;
    maxval = 255;
    Q34 = 1.5f;
    rounding = 0.5f;
    i = 0;

    // Initialize input arrays with meaningful test data
    for (int idx = 0; idx < size; idx++) {
        in[idx] = (float)(rand() % 512 - 256); // Range [-256, 255]
        scaled[idx] = fabsf(in[idx]) * 0.1f;   // Example scaling
    }
}