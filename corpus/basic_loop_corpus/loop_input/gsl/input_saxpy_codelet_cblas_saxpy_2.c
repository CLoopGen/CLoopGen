#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

int N = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
float alpha = 1.5f;
float *X;
int incX = 1;
float *Y;
int incY = 1;
int i;
int ix = 0;
int iy = 0;

void init_vars() {
    X = (float *)aligned_alloc(32, N * sizeof(float));
    Y = (float *)aligned_alloc(32, N * sizeof(float));

    if (!X || !Y) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        X[j] = (float)(rand() % 100) / 10.0f;
        Y[j] = (float)(rand() % 100) / 10.0f;
    }
}