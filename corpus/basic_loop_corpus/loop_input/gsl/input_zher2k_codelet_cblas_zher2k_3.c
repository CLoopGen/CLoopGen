#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double beta;
void *C;
int ldc;
int i;
int j;

void init_vars() {
    N = 2048;
    beta = 1.5;
    ldc = N;
    C = aligned_alloc(32, 2 * ldc * N * sizeof(double));
    if (!C) {
        exit(1);
    }
}

// End of file