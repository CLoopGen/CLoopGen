#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *quant_table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, processing every second element
    for (i = 1; i < 128; i += 2) {
        quant_table[256 - i] = -quant_table[i];
        if (i + 1 < 128) {
            quant_table[256 - (i + 1)] = -quant_table[i + 1];
        }
    }
}
