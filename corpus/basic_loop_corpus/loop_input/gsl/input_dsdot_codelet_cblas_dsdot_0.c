#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int N;
float *X;
int incX;
float *Y;
int incY;
double r;
int i;
int ix;
int iy;

void init_vars() {
    N = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime

    incX = 1;
    incY = 1;

    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));

    if (!X || !Y) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        X[j] = (float)(drand48());
        Y[j] = (float)(drand48());
    }

    r = 0.0;
    ix = 0;
    iy = 0;

    srand((unsigned int)time(NULL));
}