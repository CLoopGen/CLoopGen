#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *dst;
float *src;
int dst_stridea;
int dst_strideb;
int src_stridea;
int src_strideb;
int add;
int i;

void init_vars() {
    const size_t data_size = 16 * 256; // 16 elements per stride, 256 iterations to amplify for timing
    const size_t total_bytes = data_size * sizeof(float);

    float *src_base = (float *)aligned_alloc(32, total_bytes);
    float *dst_base = (float *)aligned_alloc(32, total_bytes);

    for (size_t idx = 0; idx < data_size; ++idx) {
        src_base[idx] = (float)(1.0f + idx * 0.001f);
        dst_base[idx] = (float)(2.0f + idx * 0.002f);
    }

    src = src_base;
    dst = dst_base;

    src_stridea = 1;
    src_strideb = 16;
    dst_stridea = 1;
    dst_strideb = 16;
    add = 1;
    i = 0;
}