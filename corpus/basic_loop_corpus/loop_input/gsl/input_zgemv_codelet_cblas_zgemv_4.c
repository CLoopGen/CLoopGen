#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *A;
int lda;
void *X;
int incX;
void *Y;
int incY;
int i;
int j;
int lenX;
int lenY;
double alpha_real;
double alpha_imag;
int ix;

static double A_data[2 * 512 * 512]; // Complex matrix: 512 x 512 elements
static double X_data[2 * 512];       // Complex vector: length 512
static double Y_data[2 * 512];       // Complex vector: length 512

void init_vars() {
    lenX = 512;
    lenY = 512;
    lda = 512;
    incX = 1;
    incY = 1;
    alpha_real = 1.5;
    alpha_imag = 0.5;
    ix = 0;

    A = A_data;
    X = X_data;
    Y = Y_data;

    for (int k = 0; k < 2 * lenX; k++) {
        X_data[k] = (double)(k + 1);
    }

    for (int k = 0; k < 2 * lenY; k++) {
        Y_data[k] = 0.0;
    }

    for (int k = 0; k < 2 * lda * lenX; k++) {
        A_data[k] = (double)(k % 100) / 100.0;
    }
}