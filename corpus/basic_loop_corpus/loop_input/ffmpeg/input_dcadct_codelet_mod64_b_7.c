#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *input;
int *output;
int i;

static int input_buffer[32 * 1048576]; // ~128 MB for input (32M integers)
static int output_buffer[16 * 1048576]; // ~64 MB for output (16M integers)

void init_vars() {
    input = input_buffer;
    output = output_buffer;

    for (size_t idx = 0; idx < 32 * 1048576; ++idx) {
        input[idx] = rand() % 1000;
    }
    for (size_t idx = 0; idx < 16 * 1048576; ++idx) {
        output[idx] = 0;
    }
}