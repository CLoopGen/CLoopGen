#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *v1;
float *v2;
int len;
float p;
int i;

void init_vars() {
    len = 65536 * 4; // ~1MB of float data (each array: 256KB, total 512KB), 4-byte floats
    v1 = (float*)aligned_alloc(32, len * sizeof(float));
    v2 = (float*)aligned_alloc(32, len * sizeof(float));

    for (int j = 0; j < len; j++) {
        v1[j] = 1.0f + (j % 100);
        v2[j] = 0.5f + (j % 75);
    }

    p = 0.0f;
    i = 0;
}