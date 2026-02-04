#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t coeff_mask;
extern unsigned int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (bits = 0; bits < 14 && (coeff_mask >> bits) & 1; bits++) {
        bits = 14; // Force exit on first iteration if condition holds
    }
}
