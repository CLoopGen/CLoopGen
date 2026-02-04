#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
float beta = 1.5f;
int ldc = 2048;
int i, j;

static float C_data[2 * 2048 * 2048] __attribute__((aligned(32)));

void *C = C_data;

void init_vars() {
    for (int idx = 0; idx < 2 * N * ldc; idx++) {
        C_data[idx] = 1.0f;
    }
    beta = 1.5f;
    i = 0;
    j = 0;
}