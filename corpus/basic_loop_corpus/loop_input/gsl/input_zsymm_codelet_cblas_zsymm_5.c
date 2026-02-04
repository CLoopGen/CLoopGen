#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

void *A;
int lda;
void *B;
int ldb;
void *C;
int ldc;
int i;
int j;
int k;
int n1;
int n2;
double alpha_real;
double alpha_imag;

static double A_data[2 * 1024 * 1024]; // 2 elements per complex number, ~16MB total
static double B_data[2 * 1024 * 1024];
static double C_data[2 * 1024 * 1024];

void init_vars() {
    // Set matrix dimensions to ensure about 0.01s runtime on modern CPU
    n1 = 512;
    n2 = 512;

    lda = n2; // leading dimension of A
    ldb = n1; // leading dimension of B
    ldc = n2; // leading dimension of C

    // Pointers to data
    A = A_data;
    B = B_data;
    C = C_data;

    // Initialize alpha with non-zero values
    alpha_real = 1.5;
    alpha_imag = 0.8;

    // Initialize A, B, C with small random-like values to avoid underflow/overflow
    for (int idx = 0; idx < 2 * n2 * n2; idx++) {
        A_data[idx] = ((double)rand() / RAND_MAX) * 0.1;
    }
    for (int idx = 0; idx < 2 * n1 * n2; idx++) {
        B_data[idx] = ((double)rand() / RAND_MAX) * 0.1;
    }
    for (int idx = 0; idx < 2 * n1 * n2; idx++) {
        C_data[idx] = ((double)rand() / RAND_MAX) * 0.1;
    }

    // Initialize loop indices to zero
    i = j = k = 0;
}