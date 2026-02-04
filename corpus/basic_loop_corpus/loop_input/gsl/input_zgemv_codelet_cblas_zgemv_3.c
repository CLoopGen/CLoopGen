#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

static double *A_data;
static double *X_data;
static double *Y_data;

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
int ix;

void init_vars() {
    lenX = 512;
    lenY = 512;
    lda = lenY;
    incX = 1;
    incY = 1;
    alpha_real = 1.5;
    alpha_imag = 0.8;
    ix = 0;

    size_t A_size = 2 * lda * lenX * sizeof(double);
    size_t X_size = 2 * ((lenX - 1) * abs(incX) + 1) * sizeof(double);
    size_t Y_size = 2 * ((lenY - 1) * abs(incY) + 1) * sizeof(double);

    A_data = (double*)calloc(1, A_size);
    X_data = (double*)calloc(1, X_size);
    Y_data = (double*)calloc(1, Y_size);

    if (!A_data || !X_data || !Y_data) {
        exit(1);
    }

    A = (void*)A_data;
    X = (void*)X_data;
    Y = (void*)Y_data;

    for (int k = 0; k < 2 * lenX; k++) {
        X_data[k] = (double)(k + 1);
    }
    for (int k = 0; k < 2 * lda * lenX; k++) {
        A_data[k] = (double)(k % 10 + 1);
    }
}