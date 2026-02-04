#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG M = 200;
BLASLONG N = 200;
BLASLONG K = 200;
float alpha0 = 1.5f;
float alpha1 = 0.5f;
float beta0 = 1.0f;
float beta1 = 0.5f;
float *C;
BLASLONG ldc = 400;
float real = 0.0f;
float imag = 0.0f;
float tmp0 = 0.0f;
float tmp1 = 0.0f;
int i = 0;
int j = 0;
int l = 0;

void init_vars() {
    C = (float*)calloc(2 * ldc * N, sizeof(float));
    if (!C) {
        exit(1);
    }
}