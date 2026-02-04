#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *bandE;
float sum[22];

void init_vars() {
    bandE = (float*)aligned_alloc(32, 22 * sizeof(float));
    if (!bandE) {
        exit(1);
    }
    for (int i = 0; i < 22; i++) {
        sum[i] = (float)(i + 1) * 0.5f;
    }
}