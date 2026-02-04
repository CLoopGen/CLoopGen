#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float h = 0.01f;
float b51 = 0.25f;
float b53 = 0.5f;
float b54 = 0.75f;
int i;

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

void init_vars() {
    const int N = 91;
    const int num_rows = 4;
    
    initvalu = (float*)calloc(N, sizeof(float));
    initvalu_temp = (float*)calloc(N, sizeof(float));
    finavalu_temp = (float**)calloc(num_rows, sizeof(float*));
    
    for (int row = 0; row < num_rows; row++) {
        finavalu_temp[row] = (float*)calloc(N, sizeof(float));
        for (int col = 0; col < N; col++) {
            finavalu_temp[row][col] = (float)(row * N + col + 1);
        }
    }

    for (int idx = 0; idx < N; idx++) {
        initvalu[idx] = (float)(idx + 1) * 0.5f;
    }
}