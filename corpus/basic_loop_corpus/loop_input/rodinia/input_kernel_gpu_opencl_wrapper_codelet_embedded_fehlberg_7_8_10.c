#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

float h = 0.01f;

float *initvalu;
float b11_1 = 0.1f;
float b11_4 = 0.2f;
float b11_5 = 0.15f;
float b11_6 = 0.1f;
float b11_7 = 0.1f;
float b11_8 = 0.1f;
float b11_9 = 0.1f;
float b11_10 = 0.1f;

float *initvalu_temp;
float **finavalu_temp;

int i;

void init_vars() {
    const int N = 91;
    const int stages = 10;

    initvalu = (float*)aligned_alloc(32, N * sizeof(float));
    initvalu_temp = (float*)aligned_alloc(32, N * sizeof(float));
    finavalu_temp = (float**)aligned_alloc(32, stages * sizeof(float*));

    for (int j = 0; j < stages; j++) {
        finavalu_temp[j] = (float*)aligned_alloc(32, N * sizeof(float));
        for (int k = 0; k < N; k++) {
            finavalu_temp[j][k] = (float)(j + 1) * 0.5f + (float)(k % 10);
        }
    }

    for (int j = 0; j < N; j++) {
        initvalu[j] = (float)(j % 8);
        initvalu_temp[j] = 0.0f;
    }
}