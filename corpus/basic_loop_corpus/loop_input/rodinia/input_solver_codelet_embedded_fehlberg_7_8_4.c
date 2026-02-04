#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <stdint.h>

float h = 0.01f;
float *initvalu;
float b51 = 0.1f;
float b53 = 0.2f;
float b54 = 0.3f;
float *initvalu_temp;
float **finavalu_temp;
int i;

void init_vars() {
    const int N = 91;
    const int stages = 4;

    initvalu = (float*)calloc(N, sizeof(float));
    initvalu_temp = (float*)calloc(N, sizeof(float));
    finavalu_temp = (float**)calloc(stages, sizeof(float*));

    for (int s = 0; s < stages; s++) {
        finavalu_temp[s] = (float*)calloc(N, sizeof(float));
        for (int j = 0; j < N; j++) {
            finavalu_temp[s][j] = (float)(s + 1) * 0.5f + (float)j * 0.01f;
        }
    }

    for (int j = 0; j < N; j++) {
        initvalu[j] = (float)j * 0.02f;
    }
}