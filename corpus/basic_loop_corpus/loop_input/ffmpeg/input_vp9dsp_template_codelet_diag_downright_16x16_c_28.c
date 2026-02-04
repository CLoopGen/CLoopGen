#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *top;
uint8_t *left;
int i;
uint8_t v[31];

static uint8_t *top_data;
static uint8_t *left_data;

void init_vars() {
    size_t data_size = 16777216; // 16MB to target ~0.01s runtime

    top_data = (uint8_t*)aligned_alloc(32, data_size);
    left_data = (uint8_t*)aligned_alloc(32, data_size);

    if (!top_data || !left_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        top_data[idx] = (uint8_t)(idx % 256);
        left_data[idx] = (uint8_t)((idx * 7) % 256);
    }

    top = top_data;
    left = left_data;

    for (int j = 0; j < 31; j++) {
        v[j] = 0;
    }
}