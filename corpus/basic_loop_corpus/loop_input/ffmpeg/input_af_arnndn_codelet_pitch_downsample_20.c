#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float **x;
float *x_lp;
int len;

void init_vars() {
    len = 1 << 20;  // Approximately 1M elements, adjust for ~0.01s runtime

    x = (float**)calloc(2, sizeof(float*));
    if (!x) exit(1);

    size_t array_size = (len << 1) + 10;  // Ensure enough space for 2*len+1 with padding
    float *data = (float*)calloc(array_size, sizeof(float));
    if (!data) exit(1);

    x[1] = data;

    x_lp = (float*)calloc(len + 10, sizeof(float));
    if (!x_lp) exit(1);

    // Initialize all arrays to non-zero values to aid computation
    for (size_t i = 0; i < array_size; i++) {
        data[i] = 1.0f + (i & 3);
    }
    for (int i = 0; i < len + 10; i++) {
        x_lp[i] = 2.0f;
    }
}