#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int N = 512;
int K = 256;
void *A;
int lda = 256;
void *B;
int ldb = 256;
void *C;
int ldc = 512;
int i, j, k;
double alpha_real = 1.5;
double alpha_imag = 0.8;

static double A_data[2 * 512 * 256];
static double B_data[2 * 512 * 256];
static double C_data[2 * 512 * 512];

void init_vars() {
    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;

    const uint64_t seed = 12345;
    srand(seed);

    for (int idx = 0; idx < 2 * N * K; idx++) {
        A_data[idx] = (double)(rand() % 1000) / 100.0;
        B_data[idx] = (double)(rand() % 1000) / 100.0;
    }

    for (int idx = 0; idx < 2 * N * ldc; idx++) {
        C_data[idx] = (double)(rand() % 1000) / 100.0;
    }
}