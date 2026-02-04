#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
uint8_t *left;
int i;
uint8_t v[15];

static uint8_t *top_data;
static uint8_t *left_data;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB to ensure ~0.01 sec runtime
    top_data = aligned_alloc(32, data_size);
    left_data = aligned_alloc(32, data_size);

    if (!top_data || !left_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        top_data[idx] = rand() & 0xFF;
        left_data[idx] = rand() & 0xFF;
    }

    top = top_data;
    left = left_data;

    for (int j = 0; j < 15; j++) {
        v[j] = 0;
    }
    i = 0;
}