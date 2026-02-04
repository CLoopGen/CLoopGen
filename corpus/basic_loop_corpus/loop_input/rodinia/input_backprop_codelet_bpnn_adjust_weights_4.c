#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *delta;
float *ly;
float **w;
float **oldw;
int ndelta;
int nly;
float new_dw;
int k;
int j;

static float *alloc_float_array(size_t n) {
    float *arr = (float *)calloc(n, sizeof(float));
    for (size_t i = 0; i < n; i++) {
        arr[i] = (float)(i % 100) / 10.0f;
    }
    return arr;
}

static float **alloc_float_matrix(int rows, int cols) {
    float **mat = (float **)calloc(rows, sizeof(float *));
    float *data = (float *)calloc(rows * cols, sizeof(float));
    for (int i = 0; i < rows; i++) {
        mat[i] = &data[i * cols];
        for (int j = 0; j < cols; j++) {
            mat[i][j] = (float)((i + j) % 200) / 100.0f;
        }
    }
    return mat;
}

void init_vars() {
    ndelta = 1000;
    nly = 500;

    delta = alloc_float_array(ndelta + 1);
    ly = alloc_float_array(nly + 1);

    w = alloc_float_matrix(nly + 1, ndelta + 1);
    oldw = alloc_float_matrix(nly + 1, ndelta + 1);

    new_dw = 0.0f;
    k = 0;
    j = 0;
}