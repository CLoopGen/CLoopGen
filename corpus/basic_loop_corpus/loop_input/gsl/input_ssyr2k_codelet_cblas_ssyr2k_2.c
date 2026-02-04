#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float beta;
float *C;
int ldc;
int i;
int j;

void init_vars() {
    N = 2048; // Size to achieve ~1-2MB of data (N*(N+1)/2 ~ 2M elements)
    beta = 1.5f;
    ldc = N;
    C = (float*)calloc(N * ldc, sizeof(float));
    if (!C) {
        exit(1);
    }
}