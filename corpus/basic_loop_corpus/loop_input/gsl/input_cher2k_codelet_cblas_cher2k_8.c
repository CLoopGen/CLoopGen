#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int N = 512;
int K = 512;
int lda = 512;
int ldb = 512;

float alpha_real = 1.5f;
float alpha_imag = 0.8f;

float *A_data;
float *B_data;
float *C_data;

void *A;
void *B;
void *C;

int i, j, k;

void init_vars() {
    size_t A_size = (size_t)K * lda * 2 * sizeof(float);
    size_t B_size = (size_t)K * ldb * 2 * sizeof(float);
    size_t C_size = (size_t)N * N * 2 * sizeof(float);

    A_data = (float *)aligned_alloc(32, A_size);
    B_data = (float *)aligned_alloc(32, B_size);
    C_data = (float *)aligned_alloc(32, C_size);

    if (!A_data || !B_data || !C_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < A_size / sizeof(float); idx++) {
        A_data[idx] = (float)(idx % 100) * 0.01f;
    }
    for (size_t idx = 0; idx < B_size / sizeof(float); idx++) {
        B_data[idx] = (float)(idx % 100) * 0.02f;
    }
    for (size_t idx = 0; idx < C_size / sizeof(float); idx++) {
        C_data[idx] = (float)(idx % 100) * 0.005f;
    }

    A = (void *)A_data;
    B = (void *)B_data;
    C = (void *)C_data;

    i = 0;
    j = 0;
    k = 0;
}