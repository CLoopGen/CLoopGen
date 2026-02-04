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
    len = 65536 * 4; // Approximately 1MB of float data (65536*4*4 bytes = 1MB)
    dst = (float*)aligned_alloc(32, len * sizeof(float));
    src = (float*)aligned_alloc(32, len * sizeof(float));
    mul = 1.5f;
    i = 0;

    for (int j = 0; j < len; j++) {
        dst[j] = (float)(j % 100);
        src[j] = (float)(j % 50);
    }
}