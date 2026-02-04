#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float float32;
typedef int int32;

float32 *dst;
float32 *src;
int32 len;
int32 i;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 million elements, ~256 MB total (two arrays)
    dst = (float32*)aligned_alloc(32, len * sizeof(float32));
    src = (float32*)aligned_alloc(32, len * sizeof(float32));

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int32 idx = 0; idx < len; idx++) {
        dst[idx] = 1.0f;
        src[idx] = 2.0f;
    }

    i = 0;
}