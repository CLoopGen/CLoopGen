#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

static double A_data[2 * 512 * 512];
static double X_data[2 * 512];
static double Y_data[2 * 512];

void *A = A_data;
int lda = 512;
void *X = X_data;
int incX = 1;
void *Y = Y_data;
int incY = 1;
int i;
int j;
int lenX = 512;
int lenY = 512;
int L = 10;
int U = 10;
double alpha_real = 1.5;
double alpha_imag = 0.5;
int ix = 0;

void init_vars() {
    for (int idx = 0; idx < 2 * 512 * 512; idx++) {
        A_data[idx] = ((double)rand() / RAND_MAX);
    }
    for (int idx = 0; idx < 2 * 512; idx++) {
        X_data[idx] = ((double)rand() / RAND_MAX);
        Y_data[idx] = ((double)rand() / RAND_MAX);
    }
}