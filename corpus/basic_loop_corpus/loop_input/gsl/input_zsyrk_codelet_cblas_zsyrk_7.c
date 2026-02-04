#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 512;
int lda = 512;
int ldc = 512;
int i, j, k;
double alpha_real = 1.0;
double alpha_imag = 0.5;

double A_data[2 * 512 * 512];
void *A = A_data;

double C_data[2 * 512 * 512];
void *C = C_data;

void init_vars() {
    for (int idx = 0; idx < 2 * N * K; idx++) {
        A_data[idx] = (double)(idx % 123) / 10.0;
    }
    for (int idx = 0; idx < 2 * N * N; idx++) {
        C_data[idx] = (double)(idx % 456) / 20.0;
    }
}