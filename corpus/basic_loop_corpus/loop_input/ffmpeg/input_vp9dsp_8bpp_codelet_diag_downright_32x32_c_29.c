#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
uint8_t *left;
int i;
uint8_t v[63];

static uint8_t *top_data;
static uint8_t *left_data;

void init_vars() {
    size_t data_size = 256 * 1024 * 1024; // 256 MB
    top_data = (uint8_t *)aligned_alloc(32, data_size);
    left_data = (uint8_t *)aligned_alloc(32, data_size);

    if (!top_data || !left_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        top_data[idx] = rand() % 256;
        left_data[idx] = rand() % 256;
    }

    top = top_data;
    left = left_data;
}