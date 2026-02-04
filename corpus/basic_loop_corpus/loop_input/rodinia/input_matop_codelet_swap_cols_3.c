#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i = 1;
int j = 2;
int lo = 0;
int hi;
int k;
double **A_me;
double tmp;

const int M = 2000;
const int N = 500;

void init_vars() {
    hi = M - 1;

    A_me = (double**)calloc(M, sizeof(double*));
    for (int idx = 0; idx < M; idx++) {
        A_me[idx] = (double*)calloc(N, sizeof(double));
        for (int jdx = 0; jdx < N; jdx++) {
            A_me[idx][jdx] = (double)(idx * N + jdx);
        }
    }

    i = 1;
    j = 2;
    lo = 0;
    hi = N - 1;
}