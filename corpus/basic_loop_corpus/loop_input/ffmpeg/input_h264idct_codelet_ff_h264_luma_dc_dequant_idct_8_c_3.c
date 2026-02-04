#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int temp[16];

static int16_t *input_data;
int16_t *input;

void init_vars() {
    const size_t input_size = 1024 * 1024; // ~1MB of data
    input_data = (int16_t*)aligned_alloc(32, input_size * sizeof(int16_t));
    if (!input_data) {
        exit(1);
    }
    for (size_t idx = 0; idx < input_size; ++idx) {
        input_data[idx] = (int16_t)(idx % 500);
    }
    input = input_data;
}