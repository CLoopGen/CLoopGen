#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
uint8_t *left;
int i;
uint8_t v[31];

static uint8_t *top_storage;
static uint8_t *left_storage;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of input data

    top_storage = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    left_storage = (uint8_t *)calloc(data_size, sizeof(uint8_t));

    if (!top_storage || !left_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        top_storage[idx] = rand() & 0xFF;
        left_storage[idx] = rand() & 0xFF;
    }

    top = top_storage;
    left = left_storage;

    for (int j = 0; j < 31; j++) {
        v[j] = 0;
    }
}