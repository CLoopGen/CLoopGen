#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

static double A_data[2 * 1024 * 1024] = {0}; // ~16MB of complex data (2 components per element)
static double X_data[2 * 1024 * 512] = {0};
static double Y_data[2 * 1024 * 512] = {0};

void *A = A_data;
int lda = 1024;
void *X = X_data;
int incX = 1;
void *Y = Y_data;
int incY = 1;
int i;
int j;
int lenX = 512;
int lenY = 512;
int L = 100;
int U = 100;
double alpha_real = 1.5;
double alpha_imag = 0.5;
int ix = 0;

void init_vars() {
    const int N = 512;
    lenX = N;
    lenY = N;
    L = 100;
    U = 100;
    alpha_real = 1.5;
    alpha_imag = 0.5;
    incX = 1;
    incY = 1;
    lda = 1024;
    ix = 0;

    for (int idx = 0; idx < 2 * lenX; idx++) {
        X_data[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (int idx = 0; idx < 2 * lenY; idx++) {
        Y_data[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (int idx = 0; idx < 2 * lda * lenX; idx++) {
        A_data[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }
}