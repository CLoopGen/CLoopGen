#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *restrict v1;
float *restrict v2;
int len;
int i;

void init_vars() {
    len = 67108864; // Approximately 256MB of data (67M * sizeof(float) * 2 ≈ 256MB)

    v1 = (float *restrict)aligned_alloc(32, len * sizeof(float));
    v2 = (float *restrict)aligned_alloc(32, len * sizeof(float));

    for (int j = 0; j < len; j++) {
        v1[j] = (float)(j % 1000) + 1.0f;
        v2[j] = (float)((j + 500) % 1000) + 0.5f;
    }
}