#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

float h = 0.01f;

float *initvalu;
float b61 = 0.5f;
float b64 = 0.3f;
float b65 = 0.2f;
float *initvalu_temp;
float **finavalu_temp;
int i;

void init_vars() {
    const int N = 91;
    const size_t data_size = 1 << 20; // ~1MB of input data per array
    const int rows = 5;

    initvalu = (float*)aligned_alloc(32, data_size);
    initvalu_temp = (float*)aligned_alloc(32, data_size);

    finavalu_temp = (float**)aligned_alloc(32, rows * sizeof(float*));
    for (int r = 0; r < rows; r++) {
        finavalu_temp[r] = (float*)aligned_alloc(32, data_size);
    }

    for (int i = 0; i < N; i++) {
        initvalu[i] = 1.0f + i * 0.1f;
        for (int r = 0; r < rows; r++) {
            finavalu_temp[r][i] = 0.1f * (r + 1);
        }
    }

    for (int i = N; i < data_size / sizeof(float); i++) {
        initvalu[i] = 0.0f;
        initvalu_temp[i] = 0.0f;
        for (int r = 0; r < rows; r++) {
            finavalu_temp[r][i] = 0.0f;
        }
    }
}