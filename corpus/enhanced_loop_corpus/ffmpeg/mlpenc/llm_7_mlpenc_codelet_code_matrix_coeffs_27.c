#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t coeff_mask;
extern unsigned int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_bits = 0;
    int32_t local_mask = coeff_mask;
    for (; local_bits < 14 && !(local_mask & (1U << local_bits)); local_bits++) {
        local_mask |= (1 << (13 - local_bits)); // Introduce WAW and RAW dependency: modifies mask used in condition
    }
    bits = local_bits;
}
