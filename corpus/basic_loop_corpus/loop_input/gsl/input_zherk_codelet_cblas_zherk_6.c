#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 512;
int K = 256;
double alpha = 1.5;
double A_data[2 * 256 * 512]; // 2 * K * N
void *A = A_data;
int lda = 512;
double C_data[2 * 512 * 512]; // 2 * N * N
void *C = C_data;
int ldc = 512;
int i, j, k;

void init_vars() {
    for (int idx = 0; idx < 2 * K * N; idx++) {
        A_data[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }
    for (int idx = 0; idx < 2 * N * N; idx++) {
        C_data[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }
    N = 512;
    K = 256;
    alpha = 1.5;
    lda = 512;
    ldc = 512;
}