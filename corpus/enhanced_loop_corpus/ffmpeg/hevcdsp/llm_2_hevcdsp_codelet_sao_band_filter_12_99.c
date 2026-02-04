#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *sao_offset_val;
extern int sao_left_class;
extern int offset_table[32];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    int base_index = sao_left_class & 31;
    for (k = 0; k < 4; k++) {
        int idx = (base_index + k) & 31;
        offset_table[idx] = sao_offset_val[k + 1];
    }
}
