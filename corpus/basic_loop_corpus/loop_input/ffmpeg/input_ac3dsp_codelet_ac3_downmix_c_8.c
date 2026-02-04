#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float **samples;
float **matrix;
int in_ch;
int len;
int i;
int j;
float v0;

void init_vars() {
    len = 8192;
    in_ch = 32;

    samples = (float**)calloc(in_ch, sizeof(float*));
    for (int idx = 0; idx < in_ch; idx++) {
        samples[idx] = (float*)calloc(len, sizeof(float));
    }

    matrix = (float**)calloc(1, sizeof(float*));
    matrix[0] = (float*)calloc(in_ch, sizeof(float));

    for (int idx = 0; idx < in_ch; idx++) {
        matrix[0][idx] = 1.0f / in_ch;
        for (int idy = 0; idy < len; idy++) {
            samples[idx][idy] = rand() / (float)RAND_MAX;
        }
    }
}