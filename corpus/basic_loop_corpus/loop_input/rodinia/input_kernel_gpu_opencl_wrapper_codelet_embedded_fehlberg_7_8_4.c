#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float h = 0.01f;
float b51 = 0.1f;
float b53 = 0.2f;
float b54 = 0.3f;
int i;

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

void init_vars() {
    const int N = 91;
    const int rows = 4;

    initvalu = (float*)calloc(N, sizeof(float));
    initvalu_temp = (float*)calloc(N, sizeof(float));
    finavalu_temp = (float**)calloc(rows, sizeof(float*));

    for (int r = 0; r < rows; r++) {
        finavalu_temp[r] = (float*)calloc(N, sizeof(float));
        for (int c = 0; c < N; c++) {
            finavalu_temp[r][c] = (float)(r + 1) * 0.5f + (float)c * 0.01f;
        }
    }

    for (int c = 0; c < N; c++) {
        initvalu[c] = (float)c * 0.02f;
    }
}