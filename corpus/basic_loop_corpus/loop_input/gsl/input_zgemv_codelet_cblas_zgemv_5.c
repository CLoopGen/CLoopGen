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
double alpha_real;
double alpha_imag;
int iy;

#define DATA_SIZE_MB 64
#define TOTAL_FLOATS (DATA_SIZE_MB * (1 << 20) / sizeof(double))

static double A_data[TOTAL_FLOATS];
static double X_data[TOTAL_FLOATS / 4];
static double Y_data[TOTAL_FLOATS / 4];

void init_vars() {
    lenY = 2048;
    lenX = 1024;
    lda = lenX;
    incX = 1;
    incY = 1;
    alpha_real = 1.5;
    alpha_imag = 0.5;
    iy = 0;

    A = A_data;
    X = X_data;
    Y = Y_data;

    for (int idx = 0; idx < lenY * lenX * 2; idx++) {
        A_data[idx] = (double)(idx % 127) / 127.0;
    }

    for (int idx = 0; idx < lenX * 2; idx++) {
        X_data[idx] = (double)(idx % 97) / 97.0;
    }

    for (int idx = 0; idx < lenY * 2; idx++) {
        Y_data[idx] = (double)(idx % 73) / 73.0;
    }
}

extern void loop();