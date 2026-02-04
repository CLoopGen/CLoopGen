#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int N = 512;
int K = 256;
double alpha = 1.5;

static double A_data[2 * 512 * 256];
void *A = A_data;

int lda = 256;

static double C_data[2 * 512 * 512];
void *C = C_data;

int ldc = 512;

int i, j, k;

void init_vars() {
    srand(0);
    for (int idx = 0; idx < 2 * N * K; idx++) {
        A_data[idx] = (double)(rand() % 100) / 10.0;
    }
    for (int idx = 0; idx < 2 * N * N; idx++) {
        C_data[idx] = (double)(rand() % 100) / 10.0;
    }
    alpha = 1.5;
    N = 512;
    K = 256;
    lda = K;
    ldc = N;
    i = j = k = 0;
}