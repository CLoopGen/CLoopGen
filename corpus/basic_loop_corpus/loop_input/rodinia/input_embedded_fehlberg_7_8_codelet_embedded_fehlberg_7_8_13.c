#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

float h = 0.01f;
float *initvalu;
float *finavalu;
float c_1_11 = 0.1f;
float c6 = 0.2f;
float c_7_8 = 0.15f;
float c_9_10 = 0.12f;
float **finavalu_temp;
int i;

void init_vars() {
    const int N = 91;
    const int stages = 11;
    
    // Allocate initvalu and finavalu arrays of size N
    initvalu = (float*)calloc(N, sizeof(float));
    finavalu = (float*)calloc(N, sizeof(float));
    
    // Allocate finavalu_temp as a 2D array: [11][N]
    finavalu_temp = (float**)calloc(stages, sizeof(float*));
    for (int s = 0; s < stages; s++) {
        finavalu_temp[s] = (float*)calloc(N, sizeof(float));
    }
    
    // Initialize initvalu with some data
    for (int idx = 0; idx < N; idx++) {
        initvalu[idx] = (float)(idx % 100) * 0.5f;
    }
    
    // Initialize finavalu_temp with pseudo-random data to simulate realistic input
    srand((unsigned int)time(NULL));
    for (int s = 0; s < stages; s++) {
        for (int idx = 0; idx < N; idx++) {
            finavalu_temp[s][idx] = (float)(rand() % 1000) / 100.0f;
        }
    }
}