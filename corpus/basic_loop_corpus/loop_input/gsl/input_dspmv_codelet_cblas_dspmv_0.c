#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 10000000;
double *Y;
int incY = 1;
int i;
int iy = 0;

void init_vars() {
    Y = (double *)aligned_alloc(32, N * sizeof(double));
    if (Y == NULL) {
        exit(EXIT_FAILURE);
    }
}