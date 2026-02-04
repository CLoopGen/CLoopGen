#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *bdata;
int j;
int k;
double mean[4];

static float *bdata_internal;

void init_vars() {
    const size_t total_size = 2048 * 1024; // ~2MB of data for sufficient runtime (~0.01 sec)
    bdata_internal = (float *)calloc(total_size, sizeof(float));
    if (!bdata_internal) {
        exit(1);
    }
    bdata = bdata_internal;

    for (size_t i = 0; i < total_size; i++) {
        bdata[i] = (float)(i % 256) / 2.0f;
    }

    j = 0;
    k = 0;

    for (int i = 0; i < 4; i++) {
        mean[i] = 0.0;
    }
}