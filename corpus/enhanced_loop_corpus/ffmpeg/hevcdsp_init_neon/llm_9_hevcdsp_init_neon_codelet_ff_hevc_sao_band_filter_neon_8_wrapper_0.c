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
    for (k = 0; k < 2; k++) {
        int base = k * 2;
        offset_table[(base + sao_left_class) & 31] = sao_offset_val[base + 1];
        offset_table[(base + 1 + sao_left_class) & 31] = sao_offset_val[base + 2];
        offset_table[(base + 2 + sao_left_class) & 31] = sao_offset_val[base + 3];
        offset_table[(base + 3 + sao_left_class) & 31] = sao_offset_val[base + 4];
    }
}
