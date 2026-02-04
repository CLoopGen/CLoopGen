#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

int N = 2048;
int K = 64;
float *A;
int lda = 2048;
float *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix = 0;

void init_vars() {
    const size_t A_size = (size_t)lda * N * sizeof(float);
    const size_t X_size = (size_t)N * sizeof(float);

    A = (float*)aligned_alloc(32, A_size);
    X = (float*)aligned_alloc(32, X_size);

    if (!A || !X) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < N; idx++) {
        X[idx] = 1.0f + idx * 0.001f;
        for (int jdx = 0; jdx < lda; jdx++) {
            A[jdx + idx * lda] = (jdx >= idx && jdx < idx + K + 1) ? (0.5f + idx * 0.0001f) : 0.0f;
        }
    }
}