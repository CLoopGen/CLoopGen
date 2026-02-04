#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float beta = 1.5f;

int ldc;
int i;
int j;
int n1;
int n2;

float *C;

void init_vars() {
    n1 = 4096;
    n2 = 4096;
    ldc = n2;

    size_t size = (size_t)ldc * n1 * sizeof(float);
    C = (float*)aligned_alloc(32, size);
    if (!C) {
        exit(1);
    }

    for (int idx = 0; idx < n1 * n2; idx++) {
        C[idx] = 1.0f;
    }

    beta = 1.5f;
}