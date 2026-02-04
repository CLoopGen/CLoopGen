#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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
float alpha_real;
float alpha_imag;
int ix;

static float *A_data;
static float *X_data;
static float *Y_data;

void init_vars() {
    lenX = 1024;
    lenY = 1024;
    L = 50;
    U = 50;
    alpha_real = 1.5f;
    alpha_imag = 0.8f;
    incX = 1;
    incY = 1;
    lda = lenY + U;
    ix = 0;

    const size_t A_size = 2 * lda * lenX; // complex float: 2 elements per entry
    const size_t X_size = 2 * ((lenX - 1) * abs(incX) + 1);
    const size_t Y_size = 2 * ((lenY - 1) * abs(incY) + 1);

    A_data = (float*)aligned_alloc(32, A_size * sizeof(float));
    X_data = (float*)aligned_alloc(32, X_size * sizeof(float));
    Y_data = (float*)aligned_alloc(32, Y_size * sizeof(float));

    for (size_t k = 0; k < A_size; k++) {
        A_data[k] = (float)(drand48() * 2.0 - 1.0);
    }
    for (size_t k = 0; k < X_size; k++) {
        X_data[k] = (float)(drand48() * 2.0 - 1.0);
    }
    for (size_t k = 0; k < Y_size; k++) {
        Y_data[k] = (float)(drand48() * 2.0 - 1.0);
    }

    A = (void*)A_data;
    X = (void*)X_data;
    Y = (void*)Y_data;
}