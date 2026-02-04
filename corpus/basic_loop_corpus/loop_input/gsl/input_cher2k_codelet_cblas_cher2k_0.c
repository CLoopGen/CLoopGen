#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;
int ldc = 4096;
int i, j;

float *C_data;
void *C;

void init_vars() {
    C_data = (float *)aligned_alloc(32, N * ldc * sizeof(float) * 2);
    if (!C_data) {
        exit(1);
    }
    C = (void *)C_data;

    for (int idx = 0; idx < N * ldc * 2; idx++) {
        C_data[idx] = (float)(idx % 1000) / 1000.0f;
    }
}