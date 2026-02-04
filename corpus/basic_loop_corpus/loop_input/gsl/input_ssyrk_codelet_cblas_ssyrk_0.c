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
    N = 8192;
    ldc = N;
    C = (float *)aligned_alloc(32, sizeof(float) * N * N);
}

__attribute__((destructor))
void cleanup() {
    if (C) {
        free(C);
    }
}