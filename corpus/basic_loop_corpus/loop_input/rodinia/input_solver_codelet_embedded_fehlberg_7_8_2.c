#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <time.h>

float h = 0.01f;
float b31 = 0.5f;
float b32 = 0.25f;
int i;

float *initvalu;
float *initvalu_temp;
float **finavalu_temp;

void init_vars() {
    const int N = 91;
    const int data_size = (1 << 20) / sizeof(float); // ~1MB of float data
    const int array_size = (data_size < N) ? N : data_size;

    initvalu = (float*)calloc(array_size, sizeof(float));
    initvalu_temp = (float*)calloc(array_size, sizeof(float));
    finavalu_temp = (float**)calloc(2, sizeof(float*));
    finavalu_temp[0] = (float*)calloc(array_size, sizeof(float));
    finavalu_temp[1] = (float*)calloc(array_size, sizeof(float));

    for (int i = 0; i < array_size; i++) {
        initvalu[i] = (float)(rand() % 100) / 10.0f;
        finavalu_temp[0][i] = (float)(rand() % 100) / 10.0f;
        finavalu_temp[1][i] = (float)(rand() % 100) / 10.0f;
    }
}