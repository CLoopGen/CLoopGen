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
int iy;

static float *A_data;
static float *X_data;
static float *Y_data;

void init_vars() {
    lenX = 1024;
    lenY = 512;
    lda = lenX;
    incX = 1;
    incY = 1;
    alpha_real = 1.5f;
    alpha_imag = 0.5f;
    iy = 0;

    size_t A_size = 2 * lda * lenY * sizeof(float);
    size_t X_size = 2 * lenX * sizeof(float);
    size_t Y_size = 2 * lenY * sizeof(float);

    A_data = (float*)aligned_alloc(32, A_size);
    X_data = (float*)aligned_alloc(32, X_size);
    Y_data = (float*)aligned_alloc(32, Y_size);

    A = (void*)A_data;
    X = (void*)X_data;
    Y = (void*)Y_data;

    for (size_t idx = 0; idx < 2 * lda * lenY; idx++) {
        A_data[idx] = (float)(idx % 100) / 100.0f;
    }
    for (size_t idx = 0; idx < 2 * lenX; idx++) {
        X_data[idx] = (float)(idx % 100) / 50.0f;
    }
    for (size_t idx = 0; idx < 2 * lenY; idx++) {
        Y_data[idx] = (float)(idx % 100) / 25.0f;
    }

    i = 0;
    j = 0;
}