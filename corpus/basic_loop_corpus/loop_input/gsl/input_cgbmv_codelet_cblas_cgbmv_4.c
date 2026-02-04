#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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

#define DATA_SIZE_MB 64

void init_vars() {
    const int total_elements = (DATA_SIZE_MB * 1024 * 1024) / sizeof(float);
    
    lenX = 2048;
    lenY = 2048;
    L = 50;
    U = 50;
    lda = lenY + 100;
    incX = 1;
    incX = 1;
    incY = 1;
    alpha_real = 1.5f;
    alpha_imag = 0.8f;
    ix = 0;

    float *A_data = (float*)calloc(2 * lda * lenX, sizeof(float));
    float *X_data = (float*)calloc(2 * lenX, sizeof(float));
    float *Y_data = (float*)calloc(2 * lenY, sizeof(float));

    A = A_data;
    X = X_data;
    Y = Y_data;

    for (int idx = 0; idx < 2 * lenX; idx++) {
        X_data[idx] = (float)(idx % 100) * 0.01f;
    }

    for (int idx = 0; idx < 2 * lenY; idx++) {
        Y_data[idx] = (float)(idx % 200) * 0.005f;
    }

    for (int j = 0; j < lenX; j++) {
        for (int i = (j > U ? j - U : 0); i < ((lenY) < (j + L + 1) ? (lenY) : (j + L + 1)); i++) {
            int A_idx = 2 * (lda * j + (U + i - j));
            if (A_idx + 1 < 2 * lda * lenX) {
                A_data[A_idx] = (float)((i + j) % 150) * 0.01f;
                A_data[A_idx + 1] = (float)((i - j + 100) % 150) * 0.01f;
            }
        }
    }
}