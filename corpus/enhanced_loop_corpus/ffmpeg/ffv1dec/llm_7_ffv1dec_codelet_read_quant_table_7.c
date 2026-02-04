#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *quant_table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 64; i++) {
        quant_table[256 - i] = -quant_table[i];
        quant_table[256 - (i + 64)] = -quant_table[i + 64];
    }
}
