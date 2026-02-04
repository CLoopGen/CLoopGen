#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

float h = 0.5f;
float b31 = 0.25f;
float b32 = 0.75f;
int i;

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

void init_vars() {
    const int N = 91;
    const int data_size = 1 << 20; // ~1MB of float data

    // Allocate and initialize initvalu and initvalu_temp
    initvalu = (float*)aligned_alloc(32, data_size);
    initvalu_temp = (float*)aligned_alloc(32, data_size);

    for (int i = 0; i < N; i++) {
        initvalu[i] = 1.0f + i * 0.1f;
        initvalu_temp[i] = 0.0f;
    }

    // Allocate finavalu_temp as array of 2 pointers
    finavalu_temp = (float**)aligned_alloc(32, 2 * sizeof(float*));
    finavalu_temp[0] = (float*)aligned_alloc(32, data_size);
    finavalu_temp[1] = (float*)aligned_alloc(32, data_size);

    for (int i = 0; i < N; i++) {
        finavalu_temp[0][i] = 0.1f * i;
        finavalu_temp[1][i] = 0.2f * i;
    }
}