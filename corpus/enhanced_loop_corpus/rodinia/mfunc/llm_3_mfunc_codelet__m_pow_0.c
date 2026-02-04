#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int p;
extern int max_bit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access simulation via lookup table for bit thresholds
    // Simulate indirect control flow using a precomputed table of bit positions
    static const int8_t bit_thresholds[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
    };
    size_t i = 0;
    for (max_bit = 0; ; max_bit++) {
        int bit_pos = bit_thresholds[i]; // Indirect access via table
        if ((p >> (bit_pos + 1)) == 0) {
            max_bit = bit_pos; // Assign final value based on indirect index
            break;
        }
        i++; // Move to next indirect index
        if (bit_pos >= 31) break; // Prevent overflow for 32-bit integers
    }
}
