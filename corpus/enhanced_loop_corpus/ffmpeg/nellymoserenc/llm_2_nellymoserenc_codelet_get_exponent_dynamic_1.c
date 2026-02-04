#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int16_t ff_nelly_delta_table[32];
extern int *idx_table;
extern int band;
extern int best_idx;
extern uint8_t (*path)[35768];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with reversed traversal using pointer arithmetic
    int16_t const* delta_base = ff_nelly_delta_table;
    int* idx_ptr = idx_table + 23 - 1;
    uint8_t* path_band;
    int temp_idx = best_idx;

    for (band = 23 - 1; band >= 0; band--) {
        path_band = path[band];
        *idx_ptr-- = path_band[temp_idx];
        if (band) {
            temp_idx -= delta_base[path_band[temp_idx]];
        }
    }
}
