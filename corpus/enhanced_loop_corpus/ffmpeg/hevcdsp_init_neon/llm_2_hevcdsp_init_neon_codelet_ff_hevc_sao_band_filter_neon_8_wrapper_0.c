#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *sao_offset_val;
extern int sao_left_class;
extern int16_t offset_table[32];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    int16_t *val_ptr = &sao_offset_val[1];
    int base_index = (sao_left_class) & 31;
    int wrap_point = 32 - base_index;

    for (k = 0; k < 4; k++) {
        int idx = base_index + k;
        if (idx >= 32) idx -= 32;
        offset_table[idx] = val_ptr[k];
    }
}
