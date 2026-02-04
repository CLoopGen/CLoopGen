#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *quant_table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 256; i++) {
        if (i <= 128) {
            quant_table[256 - i] = -quant_table[i];
        } else {
            quant_table[i] = (quant_table[i] > 0) ? quant_table[i] / 2 : (quant_table[i] - 1) / 2;
        }
    }
}
