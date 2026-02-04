#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

float h = 0.01f;
float b41 = 0.25f;
float b43 = 0.75f;
int i;

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

void init_vars() {
    const int N = 91;
    const size_t data_size = (size_t)N * sizeof(float);
    
    initvalu = (float*)calloc(N, sizeof(float));
    initvalu_temp = (float*)calloc(N, sizeof(float));
    
    finavalu_temp = (float**)calloc(3, sizeof(float*));
    for (int j = 0; j < 3; j++) {
        finavalu_temp[j] = (float*)calloc(N, sizeof(float));
    }
    
    for (int j = 0; j < N; j++) {
        initvalu[j] = (float)(rand() % 1000) / 10.0f;
        finavalu_temp[0][j] = (float)(rand() % 1000) / 10.0f;
        finavalu_temp[2][j] = (float)(rand() % 1000) / 10.0f;
    }
}