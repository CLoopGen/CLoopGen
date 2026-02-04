#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

float h = 0.01f;
float b31 = 0.25f;
float b32 = 0.75f;
int i;

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

void init_vars() {
    const int N = 91;
    const size_t data_size = 1 << 20; // ~1MB of data per array
    const int rows = 2;
    
    initvalu = (float*)calloc(data_size, sizeof(float));
    initvalu_temp = (float*)calloc(data_size, sizeof(float));
    finavalu_temp = (float**)calloc(rows, sizeof(float*));
    for (int r = 0; r < rows; r++) {
        finavalu_temp[r] = (float*)calloc(data_size, sizeof(float));
    }
    
    for (int i = 0; i < N; i++) {
        initvalu[i] = 1.0f + i * 0.1f;
        for (int r = 0; r < rows; r++) {
            finavalu_temp[r][i] = 0.5f + (r + 1) * 0.2f * i;
        }
    }
}