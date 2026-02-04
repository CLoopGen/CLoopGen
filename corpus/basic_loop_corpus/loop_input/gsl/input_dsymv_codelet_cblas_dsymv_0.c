#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 10000000; // Approximately 80 MB for double array, ensures ~0.01 sec runtime
double *Y;
int incY = 1;
int i;
int iy = 0;

void init_vars() {
    Y = (double*)aligned_alloc(64, N * sizeof(double));
    if (Y == NULL) {
        exit(EXIT_FAILURE);
    }
}