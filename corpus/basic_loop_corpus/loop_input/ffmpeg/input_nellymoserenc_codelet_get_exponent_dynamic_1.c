#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const int16_t ff_nelly_delta_table[32] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 13, 14, 15,
    -1, -2, -3, -4, -5, -6, -7, -8,
    -9, -10, -11, -12, -13, -14, -15, -16
};

int *idx_table;
int band;
int best_idx;
uint8_t (*path)[35768];

void init_vars() {
    size_t total_size = 1 << 20;
    size_t num_bands = 24;
    size_t path_stride = 35768;
    size_t total_elements = total_size / sizeof(uint8_t);

    path = aligned_alloc(64, total_elements * sizeof(uint8_t));
    idx_table = malloc(num_bands * sizeof(int));

    for (size_t i = 0; i < total_elements; ++i) {
        ((uint8_t*)path)[i] = i % 32;
    }

    for (size_t i = 0; i < num_bands; ++i) {
        idx_table[i] = 0;
    }

    best_idx = path_stride - 1;
}