#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 512;
int K = 256;
float alpha = 1.5f;

static float A_data[2 * 256 * 512]; // 2 * K * N
void *A = A_data;

int lda = 512;

static float C_data[2 * 512 * 512]; // 2 * N * N
void *C = C_data;

int ldc = 512;

int i, j, k;

void init_vars() {
    for (int idx = 0; idx < 2 * K * N; idx++) {
        A_data[idx] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
    }
    for (int idx = 0; idx < 2 * N * N; idx++) {
        C_data[idx] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
    }
    alpha = 1.5f;
    N = 512;
    K = 256;
    lda = 512;
    ldc = 512;
    i = j = k = 0;
}