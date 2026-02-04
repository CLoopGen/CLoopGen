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

double alpha_real = 1.5;
double alpha_imag = 0.8;

void *A;
void *B;
void *C;

int i, j, k;

void init_vars() {
    A = aligned_alloc(32, 2 * sizeof(double) * K * lda);
    B = aligned_alloc(32, 2 * sizeof(double) * K * ldb);
    C = aligned_alloc(32, 2 * sizeof(double) * N * lda);

    srand(0);
    double *ptrA = (double *)A;
    double *ptrB = (double *)B;
    double *ptrC = (double *)C;

    for (int idx = 0; idx < 2 * K * lda; idx++) {
        ptrA[idx] = (double)(rand()) / RAND_MAX;
    }

    for (int idx = 0; idx < 2 * K * ldb; idx++) {
        ptrB[idx] = (double)(rand()) / RAND_MAX;
    }

    for (int idx = 0; idx < 2 * N * lda; idx++) {
        ptrC[idx] = (double)(rand()) / RAND_MAX;
    }
}