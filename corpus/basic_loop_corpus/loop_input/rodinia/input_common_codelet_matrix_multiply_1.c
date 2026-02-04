#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *inputa;
float *inputb;
float *output;
int size;
int i;
int j;
int k;

void init_vars() {
    size = 512; // Choose size such that total data is about 1MB+ per array

    inputa = (float*)aligned_alloc(32, size * size * sizeof(float));
    inputb = (float*)aligned_alloc(32, size * size * sizeof(float));
    output = (float*)aligned_alloc(32, size * size * sizeof(float));

    for (int idx = 0; idx < size * size; idx++) {
        inputa[idx] = (float)((idx % 97) * 0.01f);
        inputb[idx] = (float)((idx % 89) * 0.02f);
        output[idx] = 0.0f;
    }
}