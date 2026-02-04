#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *top;
uint16_t *left;
int i;
uint16_t v[63];

static uint16_t *top_data;
static uint16_t *left_data;

void init_vars() {
    size_t data_size = 1 << 20;
    top_data = (uint16_t*)aligned_alloc(64, data_size * sizeof(uint16_t));
    left_data = (uint16_t*)aligned_alloc(64, data_size * sizeof(uint16_t));

    if (!top_data || !left_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        top_data[idx] = (uint16_t)(idx % 37);
        left_data[idx] = (uint16_t)(idx % 43);
    }

    top = top_data;
    left = left_data;

    for (int j = 0; j < 63; j++) {
        v[j] = 0;
    }
}