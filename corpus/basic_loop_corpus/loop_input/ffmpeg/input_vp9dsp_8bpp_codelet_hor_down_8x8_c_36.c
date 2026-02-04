#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
uint8_t *left;
int i;
uint8_t v[22];

static uint8_t *top_data;
static uint8_t *left_data;

void init_vars() {
    size_t data_size = 1 << 20; // ~1MB of input data

    top_data = calloc(data_size, sizeof(uint8_t));
    left_data = calloc(data_size, sizeof(uint8_t));

    if (!top_data || !left_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        top_data[idx] = rand() & 0xFF;
        left_data[idx] = rand() & 0xFF;
    }

    top = top_data + 1; // Adjust so that top[i-1] with i=0 accesses valid memory
    left = left_data;

    for (int j = 0; j < 22; j++) {
        v[j] = 0;
    }
}