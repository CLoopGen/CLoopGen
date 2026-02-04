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
float alpha_real;
float alpha_imag;
int ix;

static float *A_data;
static float *X_data;
static float *Y_data;

void init_vars() {
    lenX = 512;
    lenY = 512;
    lda = lenY;

    incX = 1;
    incY = 1;
    alpha_real = 1.5f;
    alpha_imag = 0.8f;
    ix = 0;

    size_t A_size = 2 * lda * lenX * sizeof(float);
    size_t X_size = 2 * (abs(incX) * (lenX - 1) + 1) * sizeof(float);
    size_t Y_size = 2 * (abs(incY) * (lenY - 1) + 1) * sizeof(float);

    A_data = (float*)aligned_alloc(32, A_size);
    X_data = (float*)aligned_alloc(32, X_size);
    Y_data = (float*)aligned_alloc(32, Y_size);

    A = (void*)A_data;
    X = (void*)X_data;
    Y = (void*)Y_data;

    for (size_t k = 0; k < A_size / sizeof(float); k++) {
        A_data[k] = (float)(k % 128) * 0.01f;
    }

    for (size_t k = 0; k < X_size / sizeof(float); k++) {
        X_data[k] = (float)(k % 64) * 0.02f;
    }

    for (size_t k = 0; k < Y_size / sizeof(float); k++) {
        Y_data[k] = 0.0f;
    }
}