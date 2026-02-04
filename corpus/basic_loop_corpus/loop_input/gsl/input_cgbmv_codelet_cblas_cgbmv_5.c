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
int L;
int U;
float alpha_real;
float alpha_imag;
int iy;

static float A_data[200000] __attribute__((aligned(32)));
static float X_data[10000] __attribute__((aligned(32)));
static float Y_data[10000] __attribute__((aligned(32)));

void init_vars() {
    lenY = 1000;
    lenX = 1000;
    L = 50;
    U = 50;
    lda = 100;
    incX = 1;
    incY = 2;
    alpha_real = 1.5f;
    alpha_imag = 0.8f;
    iy = 0;

    A = A_data;
    X = X_data;
    Y = Y_data;

    for (int idx = 0; idx < 200000; idx++) {
        A_data[idx] = (float)(idx % 128) / 64.0f - 1.0f;
    }
    for (int idx = 0; idx < 10000; idx++) {
        X_data[idx] = (float)(idx % 256) / 128.0f - 1.0f;
        Y_data[idx] = 0.0f;
    }
}