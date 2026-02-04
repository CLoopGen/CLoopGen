#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *quant_table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp;
    for (i = 1; i < 128; i++) {
        temp = quant_table[i];
        quant_table[256 - i] = -temp;
    }
}
