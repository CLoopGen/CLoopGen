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



void loop(){
    int temp_best_idx = best_idx;
    for (band = 23 - 1; band >= 0; band--) {
        int current_delta = ff_nelly_delta_table[path[band][temp_best_idx]];
        idx_table[band] = path[band][temp_best_idx];
        if (band) {
            temp_best_idx -= current_delta;
        }
    }
    best_idx = temp_best_idx;
}
