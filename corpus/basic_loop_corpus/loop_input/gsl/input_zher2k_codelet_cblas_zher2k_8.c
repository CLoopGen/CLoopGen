#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 512;
int K = 64;
int lda = 512;
int ldb = 512;

double alpha_real = 1.5;
double alpha_imag = 0.8;

double *A_data;
double *B_data;
double *C_data;

void *A;
void *B;
void *C;

int i, j, k;

void init_vars() {
    A_data = (double*)calloc(2 * K * lda, sizeof(double));
    B_data = (double*)calloc(2 * K * ldb, sizeof(double));
    C_data = (double*)calloc(2 * N * lda, sizeof(double));

    for (int idx = 0; idx < 2 * K * lda; idx++) {
        A_data[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }
    for (int idx = 0; idx < 2 * K * ldb; idx++) {
        B_data[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }
    for (int idx = 0; idx < 2 * N * lda; idx++) {
        C_data[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;
}