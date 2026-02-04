#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 131072;
float *Y;
int incY = 1;
int i;
int iy = 0;

void init_vars() {
    Y = aligned_alloc(32, N * 2 * sizeof(float));
    if (!Y) {
        exit(1);
    }
    for (int idx = 0; idx < N * 2; idx++) {
        Y[idx] = (float)(idx + 1);
    }
}