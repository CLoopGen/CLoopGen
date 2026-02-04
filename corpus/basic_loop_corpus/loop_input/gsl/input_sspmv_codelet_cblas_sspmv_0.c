#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float *Y;
int incY;
int i;
int iy;

void init_vars() {
    N = 1 << 20; // 1 million elements, ~4MB for float array
    Y = (float *)aligned_alloc(32, N * sizeof(float));
    if (!Y) {
        exit(1);
    }
    incY = 1;
    iy = 0;
}