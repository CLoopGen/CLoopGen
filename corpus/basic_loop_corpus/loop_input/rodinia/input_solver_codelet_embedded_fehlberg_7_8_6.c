#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float h = 0.01f;

float *initvalu;
float b71 = 0.25f;
float b74 = 0.15f;
float b75 = 0.35f;
float b76 = 0.25f;

float *initvalu_temp;
float **finavalu_temp;

int i;

void init_vars() {
    const int N = 91;
    const int M = 6; 

    initvalu = (float*)calloc(N, sizeof(float));
    initvalu_temp = (float*)calloc(N, sizeof(float));
    finavalu_temp = (float**)calloc(M, sizeof(float*));

    for (int j = 0; j < M; j++) {
        finavalu_temp[j] = (float*)calloc(N, sizeof(float));
        for (int k = 0; k < N; k++) {
            finavalu_temp[j][k] = (float)(j * N + k);
        }
    }

    for (int k = 0; k < N; k++) {
        initvalu[k] = (float)k;
    }
}