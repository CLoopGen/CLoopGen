#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *dst;
float *src0;
float *src1;
int len;
int i;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(float); // ~256 MB total data (3 arrays), ~64M elements
    size_t bytes = len * sizeof(float);

    dst = (float *)aligned_alloc(32, bytes);
    src0 = (float *)aligned_alloc(32, bytes);
    src1 = (float *)aligned_alloc(32, bytes);

    for (int j = 0; j < len; j++) {
        src0[j] = 1.0f + (j % 100) * 0.01f;
        src1[j] = 2.0f + (j % 100) * 0.02f;
    }
}