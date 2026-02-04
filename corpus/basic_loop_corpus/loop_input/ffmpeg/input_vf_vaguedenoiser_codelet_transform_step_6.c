#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float analysis_high[7] = {1.0f, 0.9f, 0.8f, 0.7f, 0.8f, 0.9f, 1.0f};

float *input;
float *output;
int low_size;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB total input to ensure loop runtime ~0.01s
    low_size = data_size / 2; // since input uses 2*i offset, scale down

    // Adjust low_size so that the loop accesses valid indices
    // Loop runs: i from 10 to 10 + low_size - 1
    // Max index in input: 2*i - 6 -> 2*(10 + low_size - 1) - 6 = 2*low_size + 12
    const int max_input_index = 2 * (10 + low_size - 1) - 6;
    const int min_input_index = 2 * 10 - 12; // 2*i -12 at i=10

    if (min_input_index < 0) {
        low_size += (12 - min_input_index); // ensure non-negative access
    }

    const size_t input_size = (size_t)(max_input_index + 1);
    const size_t output_size = (size_t)(10 + low_size + low_size); // i + low_size max index

    input = (float*)calloc(input_size, sizeof(float));
    output = (float*)calloc(output_size, sizeof(float));

    for (size_t idx = 0; idx < input_size; idx++) {
        input[idx] = (float)((rand() % 1000) / 1000.0);
    }

    for (size_t idx = 0; idx < output_size; idx++) {
        output[idx] = 0.0f;
    }
}