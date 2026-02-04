#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define MATRIX_DIM 1024

float *lu;
int matrix_dim = MATRIX_DIM;
int i;
int j;
int k;
float *tmp;

void init_vars() {
    lu = (float*)aligned_alloc(32, matrix_dim * matrix_dim * sizeof(float));
    tmp = (float*)aligned_alloc(32, matrix_dim * matrix_dim * sizeof(float));

    for (int idx = 0; idx < matrix_dim * matrix_dim; idx++) {
        lu[idx] = (float)(idx % 100) / 10.0f;
        tmp[idx] = 0.0f;
    }
}