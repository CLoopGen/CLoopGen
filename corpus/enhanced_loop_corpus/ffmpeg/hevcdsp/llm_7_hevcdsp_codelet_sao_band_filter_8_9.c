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
    offset_table[(0 + sao_left_class) & 31] = sao_offset_val[1];
    offset_table[(1 + sao_left_class) & 31] = sao_offset_val[2];
    offset_table[(2 + sao_left_class) & 31] = sao_offset_val[3];
    offset_table[(3 + sao_left_class) & 31] = sao_offset_val[4];
}
