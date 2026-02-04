#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int N = 512;
int K = 256;
int lda = 512;
int ldc = 512;
float alpha_real = 1.2f;
float alpha_imag = 0.8f;
void *A = NULL;
void *C = NULL;
int i, j, k;

static float A_data[2 * 256 * 512] __attribute__((aligned(32)));
static float C_data[2 * 512 * 512] __attribute__((aligned(32)));

void init_vars() {
    A = (void*)A_data;
    C = (void*)C_data;

    for (int idx = 0; idx < 2 * K * lda; idx++) {
        A_data[idx] = ((float)(rand() % 100)) / 100.0f;
    }

    for (int idx = 0; idx < 2 * N * ldc; idx++) {
        C_data[idx] = ((float)(rand() % 100)) / 100.0f;
    }

    i = 0;
    j = 0;
    k = 0;
}