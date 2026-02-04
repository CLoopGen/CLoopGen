#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *output;
float *input;
float iir[5][4];
float hist[5][2];
ptrdiff_t factor;
float res;
float tmp;
int i;
int j;
int k;

void init_vars() {
    const int input_size = 64;
    const int output_size = input_size * 8 * 5; // factor * 5 filters per input
    factor = 8;

    input = (float*)aligned_alloc(32, input_size * sizeof(float));
    output = (float*)aligned_alloc(32, output_size * sizeof(float));

    for (int idx = 0; idx < input_size; idx++) {
        input[idx] = 1.0f / (idx + 1);
    }

    for (int k = 0; k < 5; k++) {
        for (int c = 0; c < 4; c++) {
            iir[k][c] = (c % 2 == 0) ? 0.25f : -0.15f;
        }
        hist[k][0] = 0.0f;
        hist[k][1] = 0.0f;
    }

    res = 0.0f;
    tmp = 0.0f;
    i = 0;
    j = 0;
    k = 0;
}