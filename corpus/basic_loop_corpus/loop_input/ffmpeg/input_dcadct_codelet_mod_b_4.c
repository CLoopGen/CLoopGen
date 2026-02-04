#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *input;
int *output;
int i;

static int input_buffer[16777216];  // ~64 MB of input data (16M int elements)
static int output_buffer[8388608]; // ~32 MB of output data (8M int elements)

void init_vars() {
    input = input_buffer;
    output = output_buffer;

    for (size_t idx = 0; idx < 16777216; ++idx) {
        input[idx] = rand() % 1000;
    }

    for (size_t idx = 0; idx < 8388608; ++idx) {
        output[idx] = 0;
    }
}