#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t coeff_mask;
extern unsigned int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_bits = 0;
    for (; temp_bits < 14; temp_bits++) {
        if (coeff_mask & (1 << temp_bits)) {
            break;
        }
    }
    bits = temp_bits;
}
