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
    const int M = 3;
    size_t total_size = 1 << 20; // Aim for ~1MB of data
    size_t element_size = sizeof(float);
    size_t num_elements = total_size / element_size;
    size_t array_size = (num_elements / N) * N;
    if (array_size == 0) array_size = N;

    initvalu = (float*)calloc(array_size, sizeof(float));
    initvalu_temp = (float*)calloc(array_size, sizeof(float));

    finavalu_temp = (float**)calloc(M, sizeof(float*));
    for (int j = 0; j < M; j++) {
        finavalu_temp[j] = (float*)calloc(array_size, sizeof(float));
    }

    for (size_t j = 0; j < array_size; j++) {
        initvalu[j] = (float)(rand()) / RAND_MAX;
        for (int k = 0; k < M; k++) {
            finavalu_temp[k][j] = (float)(rand()) / RAND_MAX;
        }
    }
}