#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *src;
int len;
int i;

void init_vars() {
    len = 67108864; // ~256 MB of float data (67M elements * 4 bytes)
    src = (float*)aligned_alloc(32, len * sizeof(float));
    if (!src) {
        exit(1);
    }
    for (int j = 0; j < len; j++) {
        src[j] = (float)(rand() % 100) / 10.0f;
    }
}