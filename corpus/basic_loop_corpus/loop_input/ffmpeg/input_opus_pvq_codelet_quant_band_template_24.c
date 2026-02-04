#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *Y;
int N;
int i;

void init_vars() {
    N = 65536 * 4;  // ~256KB of float data (65536*4*4 = 1MB)
    Y = (float*)aligned_alloc(32, N * sizeof(float));
    if (!Y) {
        exit(1);
    }
    for (int j = 0; j < N; j++) {
        Y[j] = (float)(j % 1000);
    }
}