#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int K;
void *C;
int ldc;
int i;
int j;
int k;
int n1;
int n2;
int ldf;
int ldg;
int conjF;
int conjG;
float *F;
float *G;
float alpha_real;
float alpha_imag;

static float *alloc_and_init_float_array(size_t size) {
    float *ptr = (float *)calloc(size, sizeof(float));
    for (size_t i = 0; i < size; ++i) {
        ptr[i] = (float)(drand48() * 2.0 - 1.0);
    }
    return ptr;
}

void init_vars() {
    n1 = 128;
    n2 = 128;
    K = 128;
    ldc = n2;
    ldf = K;
    ldg = n2;
    conjF = 1;
    conjG = 1;
    alpha_real = 1.0f;
    alpha_imag = 0.5f;

    const size_t F_size = 2 * ldf * n1;
    const size_t G_size = 2 * ldg * K;
    const size_t C_size = 2 * ldc * n1;

    F = alloc_and_init_float_array(F_size);
    G = alloc_and_init_float_array(G_size);
    C = calloc(C_size, sizeof(float));
}