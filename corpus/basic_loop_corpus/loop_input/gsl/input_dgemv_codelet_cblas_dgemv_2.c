#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double alpha;
double *A;
int lda;
double *X;
int incX;
double *Y;
int incY;
int i;
int j;
int lenX;
int lenY;
int iy;

void init_vars() {
    lenX = 1024;
    lenY = 1024;
    lda = lenX;
    incX = 1;
    incY = 1;
    alpha = 1.5;

    A = (double*)calloc(lenX * lenY, sizeof(double));
    X = (double*)calloc(lenX, sizeof(double));
    Y = (double*)calloc(lenY, sizeof(double));

    for (int k = 0; k < lenX; k++) {
        X[k] = (double)(k % 128) / 64.0;
    }
    for (int k = 0; k < lenY; k++) {
        Y[k] = (double)(k % 256) / 128.0;
    }
    for (int k = 0; k < lenX * lenY; k++) {
        A[k] = (double)(k % 512) / 256.0;
    }

    i = 0;
    j = 0;
    iy = 0;
}