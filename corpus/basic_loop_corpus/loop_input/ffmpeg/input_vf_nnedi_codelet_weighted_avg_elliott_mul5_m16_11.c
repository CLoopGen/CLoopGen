#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(float))

float *w;
int n;
float vsum;
float wsum;
int i;

void init_vars() {
    n = TOTAL_ELEMENTS / 2;  

    w = (float*)aligned_alloc(32, TOTAL_ELEMENTS * sizeof(float));
    if (!w) {
        exit(1);
    }

    for (int idx = 0; idx < TOTAL_ELEMENTS; idx++) {
        w[idx] = (float)(rand() % 100) * 0.1f - 5.0f;
    }

    vsum = 0.0f;
    wsum = 0.0f;
    i = 0;
}