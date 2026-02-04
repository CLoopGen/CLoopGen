#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *tmp;
float *X;
int N0;
int stride;
int i;
int j;
uint8_t *order;

void init_vars() {
    stride = 512;
    N0 = 512;

    X = (float *)aligned_alloc(32, sizeof(float) * N0 * stride);
    tmp = (float *)aligned_alloc(32, sizeof(float) * stride * N0);
    order = (uint8_t *)aligned_alloc(32, sizeof(uint8_t) * stride);

    for (int idx = 0; idx < N0 * stride; idx++) {
        X[idx] = (float)(idx % 1000) / 100.0f;
    }

    for (int idx = 0; idx < stride; idx++) {
        order[idx] = (uint8_t)(idx % 256);
    }
}