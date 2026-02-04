#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1048576; // 1MB of float data: 1048576 elements
float *Y;
int incY = 1;
int i;
int iy = 0;

void init_vars() {
    Y = (float*)aligned_alloc(32, N * sizeof(float));
    if (!Y) {
        exit(EXIT_FAILURE);
    }
}