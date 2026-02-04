#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t level_code[266];
extern uint8_t level_bits[266];
extern int16_t level_symbols[266];
extern int entry;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    for (i = 0; i < 256; i += 2) {
        int index1 = entry + i;
        int index2 = entry + i + 1;

        level_code[index1] = i << 2;
        level_bits[index1] = 10;
        level_symbols[index1] = i;

        if (i + 1 < 256) {  // Prevent overflow at boundary
            level_code[index2] = (i + 1) << 2;
            level_bits[index2] = 10;
            level_symbols[index2] = i + 1;
        }
    }
    entry += 256;  // Update entry after block write
}
