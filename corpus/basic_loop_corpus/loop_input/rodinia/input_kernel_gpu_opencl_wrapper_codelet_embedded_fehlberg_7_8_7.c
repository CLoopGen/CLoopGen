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
    const int stages = 7;

    initvalu = (float*)aligned_alloc(32, N * sizeof(float));
    initvalu_temp = (float*)aligned_alloc(32, N * sizeof(float));
    finavalu_temp = (float**)aligned_alloc(32, stages * sizeof(float*));

    for (int s = 0; s < stages; s++) {
        finavalu_temp[s] = (float*)aligned_alloc(32, N * sizeof(float));
        for (int j = 0; j < N; j++) {
            finavalu_temp[s][j] = (float)(s * N + j) * 0.001f;
        }
    }

    for (int j = 0; j < N; j++) {
        initvalu[j] = (float)j * 0.1f;
        initvalu_temp[j] = 0.0f;
    }
}