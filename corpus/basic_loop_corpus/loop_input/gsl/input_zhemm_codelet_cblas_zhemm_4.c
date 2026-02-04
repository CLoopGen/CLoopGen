#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double A_data[2 * 1024 * 1024] = {0}; // Simulated complex matrix A (n2 x n2)
double B_data[2 * 1024 * 1024] = {0}; // Simulated complex matrix B (n1 x n2)
double C_data[2 * 1024 * 1024] = {0}; // Simulated complex matrix C (n1 x n2)

void* A = A_data;
void* B = B_data;
void* C = C_data;

int lda = 1024;
int ldb = 1024;
int ldc = 1024;

int i = 0;
int j = 0;
int k = 0;
int n1 = 512;  // rows of B and C
int n2 = 512;  // cols of A, B, C

double alpha_real = 1.5;
double alpha_imag = 0.8;

void init_vars() {
    const int seed = 42;
    srand(seed);

    for (int idx = 0; idx < 2 * lda * n2; ++idx) {
        ((double*)A)[idx] = (double)(rand()) / RAND_MAX * 2.0 - 1.0;
    }

    for (int idx = 0; idx < 2 * ldb * n2; ++idx) {
        ((double*)B)[idx] = (double)(rand()) / RAND_MAX * 2.0 - 1.0;
    }

    for (int idx = 0; idx < 2 * ldc * n2; ++idx) {
        ((double*)C)[idx] = (double)(rand()) / RAND_MAX * 2.0 - 1.0;
    }

    alpha_real = 1.5;
    alpha_imag = 0.8;
    n1 = 512;
    n2 = 512;
    lda = 1024;
    ldb = 1024;
    ldc = 1024;
}