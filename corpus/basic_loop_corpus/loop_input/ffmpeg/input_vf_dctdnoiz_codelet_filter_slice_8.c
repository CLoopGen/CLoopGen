#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int y;
int w = 1024;
int slice_start = 0;
int slice_end = 256;
int dst_linesize = 1024;
int slice_linesize = 1024;
float *dst;
float *weights;
float *slice;

void init_vars() {
    const size_t total_size = (size_t)(slice_end - slice_start) * dst_linesize * sizeof(float);

    dst = (float*)aligned_alloc(32, total_size);
    weights = (float*)aligned_alloc(32, total_size);
    slice = (float*)aligned_alloc(32, total_size);

    if (!dst || !weights || !slice) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size / sizeof(float); i++) {
        dst[i] = 1.0f;
        weights[i] = 2.0f;
        slice[i] = 3.0f;
    }
}