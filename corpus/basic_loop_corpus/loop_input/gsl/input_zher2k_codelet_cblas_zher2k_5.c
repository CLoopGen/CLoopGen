#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int N = 512;
int K = 512;
void *A;
int lda = 512;
void *B;
int ldb = 512;
void *C;
int ldc = 512;
int i;
int j;
int k;
double alpha_real = 1.5;
double alpha_imag = 0.8;

static double A_data[2 * 512 * 512];
static double B_data[2 * 512 * 512];
static double C_data[2 * 512 * 512];

void init_vars() {
    A = (void*)A_data;
    B = (void*)B_data;
    C = (void*)C_data;

    const uint64_t seed = 12345;
    uint64_t state = seed;

    for (int idx = 0; idx < 2 * N * K; idx++) {
        state = state * 1103515245 + 12345;
        A_data[idx] = (double)((int64_t)state % 1000) / 100.0;
    }

    for (int idx = 0; idx < 2 * N * K; idx++) {
        state = state * 1103515245 + 12345;
        B_data[idx] = (double)((int64_t)state % 1000) / 100.0;
    }

    for (int idx = 0; idx < 2 * N * N; idx++) {
        state = state * 1103515245 + 12345;
        C_data[idx] = (double)((int64_t)state % 1000) / 100.0;
    }
}