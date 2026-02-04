#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

float *vals;
int n = 8192;
int len = 8192;
float *scale;
int16_t *data;
int16_t *weights;
float *wf;
int i;
int j;

void init_vars() {
    vals = (float*)aligned_alloc(32, n * sizeof(float));
    scale = (float*)aligned_alloc(32, sizeof(float));
    data = (int16_t*)aligned_alloc(32, len * sizeof(int16_t));
    weights = (int16_t*)aligned_alloc(32, n * len * sizeof(int16_t));
    wf = (float*)aligned_alloc(32, (n * 2 + 8) * sizeof(float)); // Ensure enough space for off+4

    *scale = 1.0f;
    for (int idx = 0; idx < len; idx++) {
        data[idx] = (int16_t)(idx % 256 - 128);
    }
    for (int idx = 0; idx < n * len; idx++) {
        weights[idx] = (int16_t)(rand() % 256 - 128);
    }
    int wf_len = (n >> 2) * 8 + 8 + 4;
    for (int idx = 0; idx < wf_len; idx++) {
        wf[idx] = 1.0f + (rand() % 100) / 100.0f;
    }

    for (int idx = 0; idx < n; idx++) {
        vals[idx] = 0.0f;
    }
}