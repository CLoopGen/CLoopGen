#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int i;
int16_t *block;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB of data
    block = (int16_t*)aligned_alloc(32, data_size);
    if (!block) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (size_t idx = 0; idx < data_size / sizeof(int16_t); ++idx) {
        block[idx] = (int16_t)(rand() % 1000 - 500);
    }
}