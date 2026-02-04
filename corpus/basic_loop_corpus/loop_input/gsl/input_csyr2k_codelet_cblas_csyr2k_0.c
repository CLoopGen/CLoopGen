#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int ldc = 1024;
int i, j;

float *C_data;
void *C;

void init_vars() {
    C_data = (float *)aligned_alloc(32, sizeof(float) * 2 * ldc * N);
    if (!C_data) {
        exit(1);
    }
    C = (void *)C_data;

    for (int idx = 0; idx < 2 * ldc * N; idx++) {
        C_data[idx] = (float)(idx % 1000);
    }
}