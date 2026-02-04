#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

static float *A_data;
static float *X_data;
static float *Y_data;

void *A;
void *X;
void *Y;
int lda;
int incX;
int incY;
int i;
int j;
int lenX;
int lenY;
int L;
int U;
int iy;

float alpha_real;
float alpha_imag;

void init_vars() {
    // Set problem size to achieve ~0.01 sec runtime on modern CPU
    // Based on typical performance, aim for moderate matrix/vector sizes
    lenX = 2048;
    lenY = 2048;
    L = 50;  // lower bandwidth
    U = 50;  // upper bandwidth
    lda = L + U + 1;  // leading dimension of A (band storage)
    incX = 1;
    incY = 1;
    alpha_real = 1.0f;
    alpha_imag = 0.5f;
    iy = 0;

    // Allocate data
    A_data = (float*)aligned_alloc(32, sizeof(float) * 2 * lda * lenY);
    X_data = (float*)aligned_alloc(32, sizeof(float) * 2 * lenX);
    Y_data = (float*)aligned_alloc(32, sizeof(float) * 2 * lenY);

    // Initialize to zero to avoid NaNs and ensure predictable behavior
    for (int i = 0; i < 2 * lda * lenY; i++) A_data[i] = 0.0f;
    for (int i = 0; i < 2 * lenX; i++) X_data[i] = ((float)rand()) / RAND_MAX;
    for (int i = 0; i < 2 * lenY; i++) Y_data[i] = ((float)rand()) / RAND_MAX;

    // Assign pointers
    A = (void*)A_data;
    X = (void*)X_data;
    Y = (void*)Y_data;
}