#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double alpha = 1.5;
double *A;
int lda;
double *X;
int incX = 1;
double *Y;
int incY = 1;
int i;
int j;
int lenX = 4096;
int lenY = 4096;
int L = 100;
int U = 100;
int jx = 0;

void init_vars() {
    const size_t A_size = (size_t)(lenX) * (L + U + 1);
    const size_t X_size = (size_t)(lenX) * abs(incX) + (incX > 0 ? 0 : (lenX - 1) * (-incX));
    const size_t Y_size = (size_t)(lenY) * abs(incY) + (incY > 0 ? 0 : (lenY - 1) * (-incY));

    A = (double*)calloc(A_size, sizeof(double));
    X = (double*)calloc(X_size, sizeof(double));
    Y = (double*)calloc(Y_size, sizeof(double));

    if (!A || !X || !Y) {
        exit(1);
    }

    for (size_t idx = 0; idx < X_size; idx++) {
        X[idx] = 1.0;
    }
    for (size_t idx = 0; idx < Y_size; idx++) {
        Y[idx] = 2.0;
    }
    for (size_t idx = 0; idx < A_size; idx++) {
        A[idx] = 0.1;
    }

    lda = L + U + 1;
}