#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;

double *A;
int lda = 2048;
double *X;
int incX = 1;
int i;
int j;
int nonunit = 1;
int ix;

void init_vars() {
    A = (double*)aligned_alloc(64, sizeof(double) * lda * N);
    X = (double*)aligned_alloc(64, sizeof(double) * N * abs(incX));
    
    for (int idx = 0; idx < N * N; idx++) {
        A[idx] = (double)(idx % 127) / 10.0;
    }
    
    for (int idx = 0; idx < N; idx++) {
        X[idx * incX] = (double)(idx % 97) / 5.0;
    }
    
    i = N;
    ix = (incX > 0 ? 0 : (N - 1) * (-incX)) + (N - 1) * incX;
    nonunit = 1;
}