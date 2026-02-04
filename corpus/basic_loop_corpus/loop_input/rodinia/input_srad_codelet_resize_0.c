#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *input;
int input_rows;
int input_cols;
float *output;
int output_rows;
int output_cols;
int i;
int j;
int i2;
int j2;

void init_vars() {
    input_rows = 1024;
    input_cols = 512;
    output_rows = 2048;
    output_cols = 512;

    size_t input_size = (size_t)input_rows * input_cols * sizeof(float);
    size_t output_size = (size_t)output_rows * output_cols * sizeof(float);

    input = (float*)malloc(input_size);
    output = (float*)malloc(output_size);

    for (size_t idx = 0; idx < input_rows * input_cols; idx++) {
        input[idx] = (float)(idx % 1000) / 100.0f;
    }

    for (size_t idx = 0; idx < output_rows * output_cols; idx++) {
        output[idx] = 0.0f;
    }
}