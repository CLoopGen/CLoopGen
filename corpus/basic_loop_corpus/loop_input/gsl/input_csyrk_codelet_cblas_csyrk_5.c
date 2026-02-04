#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 512;
int K = 256;
int lda = 512;
int ldc = 512;
int i, j, k;
float alpha_real = 1.0f;
float alpha_imag = 0.5f;

float A_data[2 * 256 * 512]; // 2 * K * lda
void *A = A_data;

float C_data[2 * 512 * 512]; // 2 * N * ldc
void *C = C_data;

void init_vars() {
    for (int idx = 0; idx < 2 * K * lda; idx++) {
        A_data[idx] = (float)(idx % 100) / 100.0f;
    }
    for (int idx = 0; idx < 2 * N * ldc; idx++) {
        C_data[idx] = (float)(idx % 200) / 200.0f;
    }
    N = 512;
    K = 256;
    lda = 512;
    ldc = 512;
    alpha_real = 1.0f;
    alpha_imag = 0.5f;
}