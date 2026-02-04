#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double *A_data;
double *X_data;
double *Y_data;

void *A = NULL;
int lda;
void *X = NULL;
int incX;
void *Y = NULL;
int incY;
int i;
int j;
int lenX;
int lenY;
int L;
int U;
int iy;
double alpha_real;
double alpha_imag;

void init_vars() {
    lenX = 2048;
    lenY = 2048;
    L = 100;
    U = 100;
    lda = lenX + 2*L; // ensures bandwidth fits
    incX = 1;
    incY = 1;
    alpha_real = 1.5;
    alpha_imag = 0.8;
    iy = 0;

    A_data = (double*)aligned_alloc(32, 2 * lda * lenY * sizeof(double));
    X_data = (double*)aligned_alloc(32, 2 * lenX * sizeof(double));
    Y_data = (double*)aligned_alloc(32, 2 * lenY * sizeof(double));

    A = (void*)A_data;
    X = (void*)X_data;
    Y = (void*)Y_data;

    for (int idx = 0; idx < 2 * lda * lenY; idx++) {
        A_data[idx] = (double)(idx % 127) / 127.0;
    }

    for (int idx = 0; idx < 2 * lenX; idx++) {
        X_data[idx] = (double)(idx % 113) / 113.0;
    }

    for (int idx = 0; idx < 2 * lenY; idx++) {
        Y_data[idx] = (double)(idx % 109) / 109.0;
    }
}