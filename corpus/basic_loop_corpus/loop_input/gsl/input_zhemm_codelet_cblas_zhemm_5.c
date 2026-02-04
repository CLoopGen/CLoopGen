#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double alpha_real = 1.5;
double alpha_imag = 0.8;

int n1 = 200;
int n2 = 200;

int i, j, k;
int lda = 200;
int ldb = 200;
int ldc = 200;

void *A;
void *B;
void *C;

void init_vars() {
    A = aligned_alloc(32, sizeof(double) * 2 * lda * n2);
    B = aligned_alloc(32, sizeof(double) * 2 * ldb * n1);
    C = aligned_alloc(32, sizeof(double) * 2 * ldc * n1);

    double *Ap = (double*)A;
    double *Bp = (double*)B;
    double *Cp = (double*)C;

    for (int idx = 0; idx < 2 * lda * n2; idx++) {
        Ap[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (int idx = 0; idx < 2 * ldb * n1; idx++) {
        Bp[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (int idx = 0; idx < 2 * ldc * n1; idx++) {
        Cp[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }
}