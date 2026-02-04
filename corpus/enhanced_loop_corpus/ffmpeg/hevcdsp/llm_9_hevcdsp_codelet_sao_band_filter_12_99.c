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
    for (k = 0; k < 2; k++) {
        int base = k * 2;
        int idx1 = (base + sao_left_class) & 31;
        int idx2 = (base + 1 + sao_left_class) & 31;
        offset_table[idx1] = sao_offset_val[base + 1];
        offset_table[idx2] = sao_offset_val[base + 2];
    }
}
