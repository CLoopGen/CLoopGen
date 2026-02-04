#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

float *dx;
float *dy;
BLASLONG i__1;
BLASLONG i__2;
BLASLONG i__;
float w;
float z__;
float dh11;
float dh22;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for two float arrays
    dx = (float*)calloc(data_size, sizeof(float));
    dy = (float*)calloc(data_size, sizeof(float));

    if (!dx || !dy) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        dx[idx] = 1.0f + (float)(idx % 100) * 0.01f;
        dy[idx] = 2.0f + (float)(idx % 73) * 0.02f;
    }

    dh11 = 0.75f;
    dh22 = 0.85f;

    i__ = 1;
    i__1 = 1;
    i__2 = (BLASLONG)(data_size - 1);
}