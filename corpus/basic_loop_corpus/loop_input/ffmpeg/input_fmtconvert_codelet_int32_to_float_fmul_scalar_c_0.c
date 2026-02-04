#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *dst;
int32_t *src;
float mul;
int len;
int i;

void init_vars() {
    len = 1 << 20; // 1 million elements, roughly 4MB for src and 4MB for dst

    src = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    dst = (float*)aligned_alloc(32, len * sizeof(float));

    mul = 2.5f;

    for (i = 0; i < len; i++) {
        src[i] = (int32_t)(i % 1000);
        dst[i] = 0.0f;
    }

    i = 0;
}