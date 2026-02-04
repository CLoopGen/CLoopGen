#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

void *A;
int lda;
void *B;
int ldb;
void *C;
int ldc;
int i;
int j;
int k;
int n1;
int n2;
double alpha_real;
double alpha_imag;

static double A_data[2 * 512 * 512];
static double B_data[2 * 512 * 512];
static double C_data[2 * 512 * 512];

void init_vars() {
    n1 = 512;
    n2 = 512;
    lda = 512;
    ldb = 512;
    ldc = 512;
    alpha_real = 1.5;
    alpha_imag = 0.8;

    A = A_data;
    B = B_data;
    C = C_data;

    for (int idx = 0; idx < 2 * n2 * n2; idx++) {
        A_data[idx] = (double)(idx % 123) / 123.0;
        B_data[idx] = (double)(idx % 179) / 179.0;
        C_data[idx] = (double)(idx % 97) / 97.0;
    }
}