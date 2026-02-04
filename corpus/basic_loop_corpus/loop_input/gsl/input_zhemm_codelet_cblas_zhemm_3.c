#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double *A_data;
double *B_data;
double *C_data;

void *A;
void *B;
void *C;
int lda;
int ldb;
int ldc;
int i;
int j;
int k;
int n1;
int n2;
double alpha_real;
double alpha_imag;

void init_vars() {
    n1 = 256;
    n2 = 256;
    lda = n1;
    ldb = n1;
    ldc = n1;

    alpha_real = 1.5;
    alpha_imag = 0.8;

    A_data = (double*)aligned_alloc(32, sizeof(double) * 2 * lda * n1);
    B_data = (double*)aligned_alloc(32, sizeof(double) * 2 * ldb * n2);
    C_data = (double*)aligned_alloc(32, sizeof(double) * 2 * ldc * n2);

    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;

    for (int idx = 0; idx < 2 * lda * n1; idx++) {
        A_data[idx] = (double)(idx % 128) / 64.0;
    }
    for (int idx = 0; idx < 2 * ldb * n2; idx++) {
        B_data[idx] = (double)((idx + 19) % 128) / 64.0;
    }
    for (int idx = 0; idx < 2 * ldc * n2; idx++) {
        C_data[idx] = (double)((idx + 37) % 128) / 64.0;
    }
}