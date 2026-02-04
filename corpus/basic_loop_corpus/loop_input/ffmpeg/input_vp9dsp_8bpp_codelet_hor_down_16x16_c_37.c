#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
uint8_t *left;
int i;
uint8_t v[46];

static uint8_t *top_storage;
static uint8_t *left_storage;

void init_vars() {
    size_t data_size = 1 << 20; // ~1MB of input data

    top_storage = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    left_storage = (uint8_t*)calloc(data_size, sizeof(uint8_t));

    if (!top_storage || !left_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        top_storage[idx] = (uint8_t)(idx % 255);
        left_storage[idx] = (uint8_t)((idx * 3) % 255);
    }

    top = top_storage + 1; // ensure index i-1 is valid when i=0
    left = left_storage + 0;

    i = 0;
}