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
    n1 = 512;
    n2 = 512;
    lda = n1;
    ldb = n1;
    ldc = n1;

    alpha_real = 1.5;
    alpha_imag = 0.8;

    size_t A_size = (size_t)lda * n1 * 2;
    size_t B_size = (size_t)ldb * n2 * 2;
    size_t C_size = (size_t)ldc * n2 * 2;

    A_data = (double*)calloc(A_size, sizeof(double));
    B_data = (double*)calloc(B_size, sizeof(double));
    C_data = (double*)calloc(C_size, sizeof(double));

    for (size_t idx = 0; idx < A_size; idx++) {
        A_data[idx] = (double)(idx % 123) * 0.01;
    }
    for (size_t idx = 0; idx < B_size; idx++) {
        B_data[idx] = (double)(idx % 234) * 0.01;
    }
    for (size_t idx = 0; idx < C_size; idx++) {
        C_data[idx] = (double)(idx % 345) * 0.01;
    }

    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;
}