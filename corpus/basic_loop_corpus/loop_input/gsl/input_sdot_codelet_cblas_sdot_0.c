#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float *X;
int incX;
float *Y;
int incY;
float r;
int i;
int ix;
int iy;

void init_vars() {
    N = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime

    incX = 1;
    incY = 1;
    ix = 0;
    iy = 0;
    r = 0.0f;

    X = (float *)malloc(N * sizeof(float));
    Y = (float *)malloc(N * sizeof(float));

    for (int j = 0; j < N; j++) {
        X[j] = 1.0f + (j % 100) * 0.01f;
        Y[j] = 2.0f - (j % 75)  * 0.02f;
    }
}