#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float h = 0.01f;
float *initvalu;
float *finavalu;
float c_1_11 = 0.1f;
float c6 = 0.2f;
float c_7_8 = 0.15f;
float c_9_10 = 0.25f;
float **finavalu_temp;
int i;

void init_vars() {
    const int N = 91;
    const int M = 11;
    size_t total_size_initvalu = N * sizeof(float);
    size_t total_size_finavalu = N * sizeof(float);
    size_t total_size_finavalu_temp = M * sizeof(float*);
    
    initvalu = (float*)malloc(total_size_initvalu);
    finavalu = (float*)malloc(total_size_finavalu);
    finavalu_temp = (float**)malloc(total_size_finavalu_temp);

    for (int idx = 0; idx < N; ++idx) {
        initvalu[idx] = (float)(idx % 100) * 0.01f;
        finavalu[idx] = 0.0f;
    }

    for (int row = 0; row < M; ++row) {
        finavalu_temp[row] = (float*)malloc(N * sizeof(float));
        for (int col = 0; col < N; ++col) {
            finavalu_temp[row][col] = (float)(row * col % 50) * 0.02f;
        }
    }
}