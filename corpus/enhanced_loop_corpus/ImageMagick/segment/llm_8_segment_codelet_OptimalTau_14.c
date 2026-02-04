#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short *extrema;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and doubled trip count
    for (i = 0; i <= 511; i++) {
        extrema[i] = (short)((i * i + 3 * i + 2) & 0xFFFF);  // Non-trivial computation with masking to fit short
    }
}
