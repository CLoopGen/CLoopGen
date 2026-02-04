#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float h = 0.001f;

float *initvalu;
float b91 = 0.1f;
float b94 = 0.2f;
float b95 = 0.3f;
float b96 = 0.4f;
float b97 = 0.5f;
float b98 = 0.6f;

float *initvalu_temp;
float **finavalu_temp;
int i;

void init_vars() {
    const int N = 91;
    const size_t data_size = 1 << 20; // ~1MB of float data per array

    initvalu = (float*)calloc(N, sizeof(float));
    initvalu_temp = (float*)calloc(N, sizeof(float));

    finavalu_temp = (float**)calloc(8, sizeof(float*));
    for (int j = 0; j < 8; j++) {
        finavalu_temp[j] = (float*)calloc(N, sizeof(float));
        for (int k = 0; k < N; k++) {
            finavalu_temp[j][k] = (float)(j * N + k) * 0.01f;
        }
    }

    for (int j = 0; j < N; j++) {
        initvalu[j] = (float)j * 0.1f;
    }
}