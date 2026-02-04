#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

float h = 0.01f;

float *initvalu;
float b12_1 = 0.1f;
float b12_6 = 0.2f;
float b12_7 = 0.3f;
float b12_8 = 0.4f;
float b12_9 = 0.5f;
float b12_10 = 0.6f;

float *initvalu_temp;
float **finavalu_temp;
int i;

void init_vars() {
    const int N = 91;
    const int stages = 10;
    
    size_t data_size = (N * stages + N) * sizeof(float);
    size_t target_size = 64 * 1024 * 1024; 
    if (data_size < target_size) {
        int factor = (target_size + data_size - 1) / data_size;
        factor = (factor < 1) ? 1 : factor;
    }

    initvalu = (float*)calloc(N, sizeof(float));
    initvalu_temp = (float*)calloc(N, sizeof(float));
    finavalu_temp = (float**)calloc(stages, sizeof(float*));

    for (int s = 0; s < stages; s++) {
        finavalu_temp[s] = (float*)calloc(N, sizeof(float));
        for (int j = 0; j < N; j++) {
            finavalu_temp[s][j] = (float)(s * 10 + j % 7);
        }
    }

    for (int j = 0; j < N; j++) {
        initvalu[j] = (float)(j % 5);
    }

    h = 0.01f;
    b12_1 = 0.1f;
    b12_6 = 0.2f;
    b12_7 = 0.3f;
    b12_8 = 0.4f;
    b12_9 = 0.5f;
    b12_10 = 0.6f;
}