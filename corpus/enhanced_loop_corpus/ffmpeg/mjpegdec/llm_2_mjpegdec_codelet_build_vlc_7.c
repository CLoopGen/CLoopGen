#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_ac;
extern uint16_t huff_sym[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled to maintain same logical behavior
    // We traverse only even indices in first pass, then odd in second, effectively simulating stride-2 access
    for (i = 0; i < 256; i += 2)
        huff_sym[i] = i + 16 * is_ac;
    for (i = 1; i < 256; i += 2)
        huff_sym[i] = i + 16 * is_ac;
}
