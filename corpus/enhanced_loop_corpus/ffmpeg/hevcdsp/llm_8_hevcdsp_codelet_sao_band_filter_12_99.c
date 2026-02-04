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
    for (k = 0; k < 8; k += 2) {
        int index = (k + sao_left_class) & 31;
        int next_index = (k + 1 + sao_left_class) & 31;
        offset_table[index] = sao_offset_val[k + 1];
        offset_table[next_index] = sao_offset_val[k + 2];
    }
}
