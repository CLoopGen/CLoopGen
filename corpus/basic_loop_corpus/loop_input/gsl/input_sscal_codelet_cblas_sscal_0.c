#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float alpha;
float *X;
int incX;
int i;
int ix;

void init_vars() {
    N = 1 << 20; // 1 million elements
    alpha = 1.5f;
    incX = 1;
    ix = 0;

    X = (float *)aligned_alloc(32, N * sizeof(float));
    if (!X) {
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        X[j] = (float)(j % 100);
    }
}