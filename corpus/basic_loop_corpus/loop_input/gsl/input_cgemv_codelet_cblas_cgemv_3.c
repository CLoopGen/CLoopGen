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
float alpha_real;
float alpha_imag;
int ix;

static float *A_data;
static float *X_data;
static float *Y_data;

void init_vars() {
    lenX = 256;
    lenY = 256;
    lda = lenY;
    incX = 1;
    incY = 1;
    alpha_real = 1.5f;
    alpha_imag = 0.8f;
    ix = 0;

    size_t A_size = 2 * lda * lenX * sizeof(float);
    size_t X_size = 2 * (1 + (lenX - 1) * abs(incX)) * sizeof(float);
    size_t Y_size = 2 * (1 + (lenY - 1) * abs(incY)) * sizeof(float);

    A_data = (float*)aligned_alloc(32, A_size);
    X_data = (float*)aligned_alloc(32, X_size);
    Y_data = (float*)aligned_alloc(32, Y_size);

    for (size_t k = 0; k < A_size / sizeof(float); k++) {
        A_data[k] = (float)(k % 128) / 64.0f;
    }
    for (size_t k = 0; k < X_size / sizeof(float); k++) {
        X_data[k] = (float)(k % 64) / 32.0f;
    }
    for (size_t k = 0; k < Y_size / sizeof(float); k++) {
        Y_data[k] = 0.0f;
    }

    A = (void*)A_data;
    X = (void*)X_data;
    Y = (void*)Y_data;
}