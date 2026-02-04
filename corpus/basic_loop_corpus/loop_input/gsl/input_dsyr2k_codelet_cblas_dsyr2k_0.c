#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double *C;
int ldc;
int i;
int j;

void init_vars() {
    N = 1024;
    ldc = N;
    C = (double*)calloc(N * N, sizeof(double));
    if (!C) {
        exit(1);
    }
}