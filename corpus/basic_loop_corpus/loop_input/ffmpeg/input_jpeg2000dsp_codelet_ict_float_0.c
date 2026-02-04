#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float f_ict_params[4] = {1.5f, 2.0f, 0.8f, 1.2f};
int csize;

float *src0;
float *src1;
float *src2;

float i0f;
float i1f;
float i2f;
int i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~256 MB for three arrays (each float is 4 bytes)
    csize = data_size / sizeof(float);

    src0 = (float*)aligned_alloc(32, data_size);
    src1 = (float*)aligned_alloc(32, data_size);
    src2 = (float*)aligned_alloc(32, data_size);

    if (!src0 || !src1 || !src2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < csize; idx++) {
        src0[idx] = 1.0f + idx * 0.001f;
        src1[idx] = 2.0f + idx * 0.002f;
        src2[idx] = 3.0f + idx * 0.003f;
    }

    i0f = 0.0f;
    i1f = 0.0f;
    i2f = 0.0f;
    i = 0;
}