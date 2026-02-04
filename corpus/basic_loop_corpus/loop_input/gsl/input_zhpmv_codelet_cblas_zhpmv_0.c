#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
void *Y;
int incY;
int i;
int iy;

void init_vars() {
    N = 1000000;
    incY = 1;
    iy = 0;
    Y = aligned_alloc(32, (2 * ((N - 1) * incY + 1) + 1) * sizeof(double));
}

__attribute__((destructor))
void cleanup() {
    if (Y) free(Y);
}