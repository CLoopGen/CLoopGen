#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

static double *A_data;
static double *X_data;
static double *Y_data;

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
int L;
int U;
double alpha_real;
double alpha_imag;
int iy;

void init_vars() {
    lenX = 2048;
    lenY = 2048;
    L = 512;
    U = 512;
    lda = lenY;
    incX = 1;
    incY = 1;
    alpha_real = 1.5;
    alpha_imag = 0.5;
    iy = 0;

    A_data = (double*)calloc(2 * lda * lenY, sizeof(double));
    X_data = (double*)calloc(2 * lenX, sizeof(double));
    Y_data = (double*)calloc(2 * lenY, sizeof(double));

    A = A_data;
    X = X_data;
    Y = Y_data;

    for (int idx = 0; idx < 2 * lenX; idx++) {
        X_data[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (int idx = 0; idx < 2 * lenY; idx++) {
        Y_data[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (int i_val = 0; i_val < lenY; i_val++) {
        int j_min = (i_val > L) ? i_val - L : 0;
        int j_max = (lenX < i_val + U + 1) ? lenX : i_val + U + 1;
        for (int j_val = j_min; j_val < j_max; j_val++) {
            int a_idx = 2 * (lda * i_val + (L + j_val - i_val));
            if (a_idx >= 0 && a_idx + 1 < 2 * lda * lenY) {
                A_data[a_idx]     = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
                A_data[a_idx + 1] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
            }
        }
    }
}