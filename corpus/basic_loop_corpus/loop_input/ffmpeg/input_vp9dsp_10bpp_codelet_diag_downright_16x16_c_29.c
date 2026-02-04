#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *top;
uint16_t *left;
int i;
uint16_t v[31];

static uint16_t top_data[18];
static uint16_t left_data[18];

void init_vars() {
    const size_t data_size = 1 << 20;
    top = aligned_alloc(32, data_size * sizeof(uint16_t));
    left = aligned_alloc(32, data_size * sizeof(uint16_t));

    for (size_t idx = 0; idx < data_size; ++idx) {
        top[idx] = (uint16_t)(idx % 32768);
        left[idx] = (uint16_t)((idx * 3) % 32768);
    }

    for (int j = 0; j < 18; ++j) {
        top_data[j] = (uint16_t)((j + 1) * 100);
        left_data[j] = (uint16_t)((j + 1) * 200);
    }

    top = top_data;
    left = left_data;

    i = 0;

    for (int j = 0; j < 31; ++j) {
        v[j] = 0;
    }
}