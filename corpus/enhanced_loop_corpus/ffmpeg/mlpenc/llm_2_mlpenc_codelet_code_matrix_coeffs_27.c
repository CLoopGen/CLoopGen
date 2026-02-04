#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t coeff_mask;
extern unsigned int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp_mask = coeff_mask;
    for (bits = 0; bits < 14; bits++) {
        if (!(temp_mask & (1 << bits))) continue;
        break;
    }
}
