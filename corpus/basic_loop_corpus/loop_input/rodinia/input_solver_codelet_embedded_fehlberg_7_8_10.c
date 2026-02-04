#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float h = 0.01f;
float *initvalu;
float b11_1 = 0.1f;
float b11_4 = 0.2f;
float b11_5 = 0.3f;
float b11_6 = 0.4f;
float b11_7 = 0.5f;
float b11_8 = 0.6f;
float b11_9 = 0.7f;
float b11_10 = 0.8f;
float *initvalu_temp;
float **finavalu_temp;
int i;

void init_vars() {
    const int N = 91;
    const int stages = 10;

    initvalu = (float*)calloc(N, sizeof(float));
    initvalu_temp = (float*)calloc(N, sizeof(float));
    finavalu_temp = (float**)calloc(stages, sizeof(float*));

    for (int s = 0; s < stages; s++) {
        finavalu_temp[s] = (float*)calloc(N, sizeof(float));
        for (int j = 0; j < N; j++) {
            finavalu_temp[s][j] = (float)(s + 1) * 0.1f;
        }
    }

    for (int j = 0; j < N; j++) {
        initvalu[j] = (float)j * 0.01f;
    }
}