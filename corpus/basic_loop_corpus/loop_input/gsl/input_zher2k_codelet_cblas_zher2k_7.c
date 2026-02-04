#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 512;
int K = 256;
int lda = 256;
int ldb = 256;
int ldc = 512;

double alpha_real = 0.8;
double alpha_imag = 0.6;

int i = 0;
int j = 0;
int k = 0;

double *A_data;
double *B_data;
double *C_data;

void *A;
void *B;
void *C;

void init_vars() {
    A_data = (double*)aligned_alloc(32, sizeof(double) * 2 * N * K);
    B_data = (double*)aligned_alloc(32, sizeof(double) * 2 * N * K);
    C_data = (double*)aligned_alloc(32, sizeof(double) * 2 * N * N);

    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;

    for (int idx = 0; idx < 2 * N * K; idx++) {
        A_data[idx] = (double)(idx % 128) / 128.0;
        B_data[idx] = (double)((idx * 7) % 128) / 128.0;
    }

    for (int idx = 0; idx < 2 * N * N; idx++) {
        C_data[idx] = (double)((idx * 13) % 256) / 256.0;
    }
}