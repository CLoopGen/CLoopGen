#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *A_data;
double *X_data;
double *Y_data;

void *A;
void *X;
void *Y;
int lda;
int incX;
int incY;
int i;
int j;
int lenX;
int lenY;
double alpha_real;
double alpha_imag;
int iy;

void init_vars() {
    lenX = 1024;
    lenY = 1024;
    lda = lenX;
    incX = 1;
    incY = 1;
    alpha_real = 1.5;
    alpha_imag = 0.8;
    iy = 0;

    size_t A_size = 2 * lda * lenY * sizeof(double);
    size_t X_size = 2 * lenX * sizeof(double);
    size_t Y_size = 2 * lenY * sizeof(double);

    A_data = (double*)aligned_alloc(32, A_size);
    X_data = (double*)aligned_alloc(32, X_size);
    Y_data = (double*)aligned_alloc(32, Y_size);

    for (size_t k = 0; k < 2 * lda * lenY; k++) {
        A_data[k] = (double)(k % 127) / 64.0;
    }
    for (size_t k = 0; k < 2 * lenX; k++) {
        X_data[k] = (double)(k % 123) / 61.0;
    }
    for (size_t k = 0; k < 2 * lenY; k++) {
        Y_data[k] = (double)(k % 113) / 59.0;
    }

    A = (void*)A_data;
    X = (void*)X_data;
    Y = (void*)Y_data;
}

void cleanup() {
    free(A_data);
    free(X_data);
    free(Y_data);
}