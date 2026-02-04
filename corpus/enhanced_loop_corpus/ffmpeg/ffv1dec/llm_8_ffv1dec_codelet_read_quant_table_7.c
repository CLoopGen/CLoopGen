#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *quant_table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 128; i += 2) {
        int16_t temp1 = quant_table[i];
        int16_t temp2 = quant_table[128 - i];
        quant_table[256 - i] = -temp1;
        quant_table[127 - i] = -temp2;
    }
}
