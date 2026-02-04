#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

int N = 512;
int K = 256;
double alpha = 1.5;

static double *A_data;
static double *C_data;

void* A;
void* C;

int lda = 256;
int ldc = 512;

int i;
int j;
int k;

void init_vars() {
    const size_t A_size = (size_t)N * (size_t)lda * 2 * sizeof(double);
    const size_t C_size = (size_t)N * (size_t)ldc * 2 * sizeof(double);

    A_data = (double*)calloc(1, A_size);
    C_data = (double*)calloc(1, C_size);

    A = (void*)A_data;
    C = (void*)C_data;

    for (size_t idx = 0; idx < A_size / sizeof(double); idx++) {
        A_data[idx] = (double)(idx % 1234) * 0.001;
    }

    for (size_t idx = 0; idx < C_size / sizeof(double); idx++) {
        C_data[idx] = (double)(idx % 1234) * 0.002;
    }
}