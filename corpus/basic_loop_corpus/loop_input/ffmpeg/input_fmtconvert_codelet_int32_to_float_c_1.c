#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

float *dst;
int32_t *src;
intptr_t len;
int i;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(int32_t); // ~256 MB of int32_t data

    src = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    dst = (float*)aligned_alloc(32, len * sizeof(float));

    if (!src || !dst) {
        exit(1);
    }

    for (intptr_t j = 0; j < len; j++) {
        src[j] = (int32_t)(j % 1000);
    }

    for (intptr_t j = 0; j < len; j++) {
        dst[j] = 0.0f;
    }

    i = 0;
}