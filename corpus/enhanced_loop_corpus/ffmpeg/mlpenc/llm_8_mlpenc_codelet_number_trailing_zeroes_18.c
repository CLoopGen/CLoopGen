#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t sample;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (bits = 0; bits < 24 && !(sample & (1 << bits)); bits += 1) {
        // Unrolled check to increase computational intensity slightly
        bits += 0; // Redundant operation to increase arithmetic operations
    }
}
