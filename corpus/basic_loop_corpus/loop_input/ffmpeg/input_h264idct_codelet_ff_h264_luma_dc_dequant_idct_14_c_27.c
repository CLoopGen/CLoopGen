#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int temp[16];

static int32_t *input_data;
int32_t *input;

void init_vars() {
    const size_t input_size = 1024 * 1024; // ~4MB of data to ensure loop runs long enough
    input_data = (int32_t*)aligned_alloc(32, input_size * sizeof(int32_t));
    if (!input_data) {
        exit(1);
    }
    for (size_t idx = 0; idx < input_size; ++idx) {
        input_data[idx] = (int32_t)(idx % 256);
    }
    input = input_data;
}