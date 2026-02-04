#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t sample;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access pattern via lookup table for bit positions
    // Simulate indirect access by using an index array that defines access order
    static const int8_t bit_order[24] = {
        0, 8, 16, 1, 9, 17, 2, 10, 18, 
        3, 11, 19, 4, 12, 20, 5, 13, 21,
        6, 14, 22, 7, 15, 23
    }; // Interleaved access simulating bank-strided or indirect pattern

    int temp_bits = 24;
    int i;

    for (i = 0; i < 24; i++) {
        int bit_index = bit_order[i];
        if (sample & (1 << bit_index)) {
            // Once first set bit is found in custom order, map back to linear position
            temp_bits = bit_index;
            break;
        }
    }

    // Now collapse all lower bits than temp_bits to find the actual first set bit
    for (bits = 0; bits < temp_bits; bits++) {
        if (sample & (1 << bits)) {
            return; // Early exit with correct `bits`
        }
    }
    bits = temp_bits; // Either points to first set bit or 24 if none
}
