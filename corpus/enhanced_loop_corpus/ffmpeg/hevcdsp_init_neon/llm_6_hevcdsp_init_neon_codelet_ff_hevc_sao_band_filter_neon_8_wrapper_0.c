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
    int16_t temp[4];
    for (k = 0; k < 4; k++) {
        temp[k] = sao_offset_val[k + 1];
    }
    for (k = 0; k < 4; k++) {
        offset_table[(k + sao_left_class) & 31] = temp[k];
    }
}
