#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float h = 0.001f;
float *initvalu;
float b71 = 0.1f;
float b74 = 0.2f;
float b75 = 0.3f;
float b76 = 0.4f;
float *initvalu_temp;
float **finavalu_temp;
int i;

void init_vars() {
    const int N = 91;
    const int M = 6;
    size_t total_size = N * sizeof(float);
    size_t ptr_array_size = M * sizeof(float*);

    initvalu = (float*)malloc(total_size);
    initvalu_temp = (float*)malloc(total_size);
    finavalu_temp = (float**)malloc(ptr_array_size);

    for (int j = 0; j < N; j++) {
        initvalu[j] = (float)(j % 100) * 0.01f;
        initvalu_temp[j] = 0.0f;
    }

    for (int k = 0; k < M; k++) {
        float* row = (float*)malloc(total_size);
        for (int j = 0; j < N; j++) {
            row[j] = (float)rand() / RAND_MAX;
        }
        finavalu_temp[k] = row;
    }
}