#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int N = 512;
int K = 512;
int lda = 512;
int ldb = 512;

float *A_data;
float *B_data;
float *C_data;

void *A = NULL;
void *B = NULL;
void *C = NULL;

int i = 0;
int j = 0;
int k = 0;

float alpha_real = 1.5f;
float alpha_imag = 0.8f;

void init_vars() {
    srand(time(NULL));

    A_data = (float*)aligned_alloc(32, sizeof(float) * 2 * K * lda);
    B_data = (float*)aligned_alloc(32, sizeof(float) * 2 * K * ldb);
    C_data = (float*)aligned_alloc(32, sizeof(float) * 2 * N * N);

    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;

    for (int idx = 0; idx < 2 * K * lda; idx++) {
        A_data[idx] = (float)(rand()) / RAND_MAX;
    }
    for (int idx = 0; idx < 2 * K * ldb; idx++) {
        B_data[idx] = (float)(rand()) / RAND_MAX;
    }
    for (int idx = 0; idx < 2 * N * N; idx++) {
        C_data[idx] = (float)(rand()) / RAND_MAX;
    }

    i = 0;
    j = 0;
    k = 0;
}