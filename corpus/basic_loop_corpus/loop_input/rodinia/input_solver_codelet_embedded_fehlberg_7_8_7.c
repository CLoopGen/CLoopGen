#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float h = 0.01f;

float *initvalu;
float b81 = 0.25f;
float b85 = 0.15f;
float b86 = 0.35f;
float b87 = 0.25f;

float *initvalu_temp;
float **finavalu_temp;
int i;

void init_vars() {
    const int N = 91;
    const int num_rows = 7;

    initvalu = (float*)aligned_alloc(32, N * sizeof(float));
    initvalu_temp = (float*)aligned_alloc(32, N * sizeof(float));
    finavalu_temp = (float**)aligned_alloc(32, num_rows * sizeof(float*));

    for (int row = 0; row < num_rows; row++) {
        finavalu_temp[row] = (float*)aligned_alloc(32, N * sizeof(float));
        for (int col = 0; col < N; col++) {
            finavalu_temp[row][col] = (float)(row + 1) * (col + 1) * 0.1f;
        }
    }

    for (int idx = 0; idx < N; idx++) {
        initvalu[idx] = idx * 0.5f;
        initvalu_temp[idx] = 0.0f;
    }
}