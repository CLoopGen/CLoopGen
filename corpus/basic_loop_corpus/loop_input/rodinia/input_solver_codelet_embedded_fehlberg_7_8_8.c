#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float h = 0.01f;

float *initvalu;
float b91 = 0.16f;
float b94 = 0.2f;
float b95 = 0.2f;
float b96 = 0.2f;
float b97 = 0.2f;
float b98 = 0.04f;

float *initvalu_temp;
float **finavalu_temp;

int i;

void init_vars() {
    const int N = 91;
    const int num_rows = 8;
    size_t data_size = 1 << 20;
    size_t total_floats = data_size / sizeof(float);
    if (total_floats < (size_t)N * num_rows + N) {
        total_floats = (size_t)N * num_rows + N;
        data_size = total_floats * sizeof(float);
    }

    float *data_pool = (float *)calloc(total_floats, sizeof(float));
    if (!data_pool) {
        exit(1);
    }

    initvalu = data_pool;
    initvalu_temp = data_pool + N;

    finavalu_temp = (float **)calloc(num_rows, sizeof(float *));
    if (!finavalu_temp) {
        exit(1);
    }

    float *current = initvalu_temp + N;
    for (int r = 0; r < num_rows; r++) {
        finavalu_temp[r] = current + r * N;
        for (int c = 0; c < N; c++) {
            finavalu_temp[r][c] = (float)(r * 0.1 + c * 0.01);
        }
    }

    for (int c = 0; c < N; c++) {
        initvalu[c] = (float)c * 0.5f;
        initvalu_temp[c] = 0.0f;
    }
}