#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float h = 0.01f;
float b41 = 0.25f;
float b43 = 0.75f;
int i;

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

void init_vars() {
    const int N = 91;
    const int total_size = 1 << 20; // ~1MB of data, adjust for timing
    
    // Allocate initvalu and initvalu_temp as arrays of N floats
    initvalu = (float*)calloc(N, sizeof(float));
    initvalu_temp = (float*)calloc(N, sizeof(float));
    
    // Allocate finavalu_temp as a 3xN matrix (we only use indices 0 and 2)
    finavalu_temp = (float**)calloc(3, sizeof(float*));
    for (int j = 0; j < 3; j++) {
        finavalu_temp[j] = (float*)calloc(N, sizeof(float));
    }
    
    // Initialize input values with some sample data to avoid all zeros
    for (int j = 0; j < N; j++) {
        initvalu[j] = (float)(j % 100) * 0.5f;
        finavalu_temp[0][j] = (float)(j % 50) * 0.1f;
        finavalu_temp[2][j] = (float)(j % 75) * 0.2f;
    }
}