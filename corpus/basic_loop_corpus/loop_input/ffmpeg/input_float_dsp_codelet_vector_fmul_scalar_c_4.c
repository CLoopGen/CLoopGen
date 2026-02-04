#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *dst;
float *src;
float mul;
int len;
int i;

void init_vars() {
    len = 67108864; // Approximately 256MB of float data (67M elements * 4 bytes * 2 arrays)
    src = (float*)aligned_alloc(32, len * sizeof(float));
    dst = (float*)aligned_alloc(32, len * sizeof(float));
    mul = 1.5f;
    i = 0;

    for (int j = 0; j < len; j++) {
        src[j] = (float)(j % 1000) / 100.0f;
    }
}