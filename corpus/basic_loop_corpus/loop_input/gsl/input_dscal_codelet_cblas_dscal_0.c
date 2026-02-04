#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double alpha;
double *X;
int incX;
int i;
int ix;

void loop();

void init_vars() {
    N = 131072; // Approximately 1MB of data (131072 * 8 bytes per double)
    alpha = 1.5;
    X = (double*)aligned_alloc(32, N * sizeof(double));
    incX = 1;
    i = 0;
    ix = 0;

    for (int j = 0; j < N; j++) {
        X[j] = (double)(j + 1);
    }
}