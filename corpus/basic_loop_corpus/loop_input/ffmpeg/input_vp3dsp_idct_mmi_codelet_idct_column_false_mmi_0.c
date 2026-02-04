#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t temp_value[8];

static int16_t *input_data;
int16_t *input;

void init_vars() {
    size_t input_size = 256 * 1024 * 1024; // 256 MB
    input_data = (int16_t *)calloc(input_size, sizeof(int16_t));
    if (!input_data) {
        exit(1);
    }
    for (size_t i = 0; i < input_size; ++i) {
        input_data[i] = rand() % 1000;
    }
    input = input_data;
}