#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *dst;
float *src;
ptrdiff_t len;
float prev;
int i;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(float); // ~256MB of float data (two outputs per input)
    src = (float *)aligned_alloc(32, len * sizeof(float));
    dst = (float *)aligned_alloc(32, 2 * len * sizeof(float)); // Twice the size for two outputs per input

    for (i = 0; i < len; i++) {
        src[i] = (float)(i % 1000) + 1.0f;
    }
    prev = 0.5f;
}