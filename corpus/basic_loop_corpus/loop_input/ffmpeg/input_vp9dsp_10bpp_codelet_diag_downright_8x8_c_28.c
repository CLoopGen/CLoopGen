#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *top;
uint16_t *left;
int i;
uint16_t v[15];

static uint16_t *top_data;
static uint16_t *left_data;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB per array to target ~0.01 sec runtime
    top_data = (uint16_t*)calloc(data_size, sizeof(uint16_t));
    left_data = (uint16_t*)calloc(data_size, sizeof(uint16_t));

    if (!top_data || !left_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        top_data[idx] = (uint16_t)(idx % 256);
        left_data[idx] = (uint16_t)((idx * 3) % 256);
    }

    top = top_data;
    left = left_data;
}