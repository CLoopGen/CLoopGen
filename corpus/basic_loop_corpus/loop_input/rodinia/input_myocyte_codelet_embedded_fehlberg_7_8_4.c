#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
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
    const size_t data_size = 1 << 20;
    const int num_arrays = 3;

    initvalu = (float*)aligned_alloc(32, data_size);
    initvalu_temp = (float*)aligned_alloc(32, data_size);

    finavalu_temp = (float**)aligned_alloc(32, num_arrays * sizeof(float*));
    for (int idx = 0; idx < num_arrays; idx++) {
        finavalu_temp[idx] = (float*)aligned_alloc(32, data_size);
        for (int j = 0; j < N; j++) {
            finavalu_temp[idx][j] = (float)(idx * 100 + j);
        }
    }

    for (int j = 0; j < N; j++) {
        initvalu[j] = (float)j;
        initvalu_temp[j] = 0.0f;
    }
}