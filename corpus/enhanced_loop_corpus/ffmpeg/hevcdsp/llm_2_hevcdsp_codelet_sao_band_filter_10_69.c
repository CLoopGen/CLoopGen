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
    // Variant 1: Consecutive memory access by reindexing with a temporary array
    int16_t temp[4];
    for (int i = 0; i < 4; i++) {
        temp[i] = sao_offset_val[i + 1];
    }
    for (k = 0; k < 4; k++) {
        offset_table[k] = temp[k];  // Write consecutively starting at offset 0
    }
}
