#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <time.h>

float h = 0.001f;

float *initvalu;
float b13_1 = 0.1f;
float b13_4 = 0.2f;
float b13_5 = 0.15f;
float b13_6 = 0.12f;
float b13_7 = 0.18f;
float b13_8 = 0.25f;
float b13_9 = 0.08f;
float b13_10 = 0.11f;

float *initvalu_temp;
float **finavalu_temp;

int i;

void init_vars() {
    const int N = 91;
    const int stages = 12;

    size_t total_data_size = 16 * 1024 * 1024; // ~16 MB of data for sufficient runtime
    size_t element_size = sizeof(float);
    size_t num_elements = total_data_size / (N * stages) + 1;

    initvalu = (float*)calloc(N, sizeof(float));
    initvalu_temp = (float*)calloc(N, sizeof(float));

    finavalu_temp = (float**)calloc(stages, sizeof(float*));
    for (int s = 0; s < stages; s++) {
        finavalu_temp[s] = (float*)calloc(N, sizeof(float));
        for (int j = 0; j < N; j++) {
            finavalu_temp[s][j] = (float)((s * 73 + j * 13 + 59) % 1000) / 100.0f;
        }
    }

    for (int j = 0; j < N; j++) {
        initvalu[j] = (float)(j % 50) / 10.0f;
    }

    h = 0.001f;
}