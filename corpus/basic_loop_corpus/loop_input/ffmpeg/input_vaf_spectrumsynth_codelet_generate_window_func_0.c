#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *lut;
int N;
int n;

void init_vars() {
    N = 1 << 24; // Approximately 16.7 million elements, ~64 MB of data (64 * 10^6 bytes)
    lut = (float *)aligned_alloc(32, N * sizeof(float));
    if (!lut) {
        exit(1);
    }
}