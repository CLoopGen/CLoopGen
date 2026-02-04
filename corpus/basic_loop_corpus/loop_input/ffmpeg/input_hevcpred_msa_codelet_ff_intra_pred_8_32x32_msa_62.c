#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *left;
uint8_t *filtered_left;

static uint8_t *left_storage;
static uint8_t *filtered_left_storage;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    left_storage = (uint8_t*)aligned_alloc(32, data_size + 2);
    filtered_left_storage = (uint8_t*)aligned_alloc(32, data_size);

    if (!left_storage || !filtered_left_storage) {
        exit(1);
    }

    left = left_storage + 1;
    filtered_left = filtered_left_storage;

    for (size_t idx = 0; idx < data_size + 1; idx++) {
        left_storage[idx] = rand() & 0xFF;
    }
}