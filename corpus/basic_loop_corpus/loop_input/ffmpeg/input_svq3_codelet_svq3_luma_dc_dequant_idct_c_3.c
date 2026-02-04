#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *input;
int i;
int temp[16];

void init_vars() {
    const size_t input_size = 1024 * 256; // 512 KB of int16_t data (~0.01 sec estimate)
    input = (int16_t*)calloc(input_size, sizeof(int16_t));
    if (!input) {
        exit(1);
    }

    for (size_t idx = 0; idx < input_size; idx++) {
        input[idx] = (int16_t)(idx % 32);
    }
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}