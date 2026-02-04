#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double alpha_real = 1.5;
double alpha_imag = 0.8;
int n1 = 200;
int n2 = 200;
int lda = 200;
int ldb = 200;
int ldc = 200;
int i, j, k;

void *A;
void *B;
void *C;

void init_vars() {
    const size_t size_a = (size_t)lda * n1 * 2 * sizeof(double);
    const size_t size_b = (size_t)ldb * n2 * 2 * sizeof(double);
    const size_t size_c = (size_t)ldc * n2 * 2 * sizeof(double);

    A = aligned_alloc(32, size_a);
    B = aligned_alloc(32, size_b);
    C = aligned_alloc(32, size_c);

    double *Ap = (double *)A;
    double *Bp = (double *)B;
    double *Cp = (double *)C;

    for (size_t idx = 0; idx < size_a / sizeof(double); idx++) {
        Ap[idx] = (double)(idx % 100) / 100.0;
    }
    for (size_t idx = 0; idx < size_b / sizeof(double); idx++) {
        Bp[idx] = (double)(idx % 100) / 100.0;
    }
    for (size_t idx = 0; idx < size_c / sizeof(double); idx++) {
        Cp[idx] = (double)(idx % 100) / 100.0;
    }
}