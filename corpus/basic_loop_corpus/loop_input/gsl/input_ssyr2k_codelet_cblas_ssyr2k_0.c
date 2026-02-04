#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float *C;
int ldc;
int i;
int j;

void init_vars() {
    N = 4096;
    ldc = N;
    C = (float *)aligned_alloc(32, sizeof(float) * N * ldc);
    if (!C) {
        exit(1);
    }
}