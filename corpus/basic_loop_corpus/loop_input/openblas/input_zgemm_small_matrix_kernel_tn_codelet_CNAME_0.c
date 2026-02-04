#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG M = 200;
BLASLONG N = 200;
BLASLONG K = 200;
float alpha0 = 1.5f;
float alpha1 = 0.8f;
float beta0 = 1.2f;
float beta1 = 0.3f;
float *C;
BLASLONG ldc = 400;
float real;
float imag;
float tmp0;
float tmp1;
int i;
int j;
int l;

void init_vars() {
    size_t total_size = M * N * 2 * ldc * sizeof(float);
    C = (float*)calloc(total_size / sizeof(float), sizeof(float));
    if (C == NULL) {
        exit(1);
    }
}