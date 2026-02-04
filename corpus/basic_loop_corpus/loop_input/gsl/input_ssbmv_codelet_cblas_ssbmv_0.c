#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1048576; // 1M elements, ~4MB for float array
float *Y;
int incY = 1;
int i;
int iy = 0;

void init_vars() {
    Y = (float*)aligned_alloc(32, N * sizeof(float));
    if (!Y) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}