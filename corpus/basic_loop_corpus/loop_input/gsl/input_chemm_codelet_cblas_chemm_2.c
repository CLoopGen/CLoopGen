#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
float alpha_real;
float alpha_imag;

static float A_data[1024 * 1024];
static float B_data[1024 * 1024];
static float C_data[1024 * 1024];

void init_vars() {
    n1 = 512;
    n2 = 256;
    lda = n1;
    ldb = n1;
    ldc = n2;
    alpha_real = 1.5f;
    alpha_imag = 0.5f;

    A = A_data;
    B = B_data;
    C = C_data;

    for (int idx = 0; idx < n1 * n1; ++idx) {
        A_data[2 * idx] = 1.0f + 0.01f * idx;
        A_data[2 * idx + 1] = 0.0f;
    }

    for (int idx = 0; idx < n1 * n2; ++idx) {
        B_data[2 * idx] = 0.5f + 0.001f * idx;
        B_data[2 * idx + 1] = 0.0f;
    }

    for (int idx = 0; idx < n1 * n2; ++idx) {
        C_data[2 * idx] = 0.0f;
        C_data[2 * idx + 1] = 0.0f;
    }
}