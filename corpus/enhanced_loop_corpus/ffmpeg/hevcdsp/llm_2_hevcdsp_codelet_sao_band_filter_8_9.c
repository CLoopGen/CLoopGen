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
    // Variant 1: Consecutive memory access with pointer arithmetic
    int16_t *val_ptr = sao_offset_val + 1;
    int *offset_ptr = offset_table + sao_left_class;
    for (k = 0; k < 4; k++) {
        offset_ptr[k & 31] = val_ptr[k];
    }
}
