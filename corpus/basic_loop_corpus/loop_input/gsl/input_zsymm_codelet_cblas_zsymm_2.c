#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double *A_data;
double *B_data;
double *C_data;

void *A = NULL;
void *B = NULL;
void *C = NULL;
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
    n2 = 256;
    lda = n1;
    ldb = n1;
    ldc = n1;

    alpha_real = 0.8;
    alpha_imag = 0.6;

    A_data = (double*)calloc(2 * n1 * lda, sizeof(double));
    B_data = (double*)calloc(2 * n1 * n2, sizeof(double));
    C_data = (double*)calloc(2 * n1 * n2, sizeof(double));

    for (int idx = 0; idx < 2 * n1 * lda; idx++) {
        A_data[idx] = (double)(idx % 127) / 10.0;
    }

    for (int idx = 0; idx < 2 * n1 * n2; idx++) {
        B_data[idx] = (double)(idx % 131) / 10.0;
    }

    for (int idx = 0; idx < 2 * n1 * n2; idx++) {
        C_data[idx] = (double)(idx % 137) / 10.0;
    }

    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;
}