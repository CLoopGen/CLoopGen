#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t count;
extern ssize_t j;
extern unsigned char c;
extern unsigned short bits[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Remapping
    // Use a precomputed permutation table to write into 'bits' in non-linear order.
    // The computation remains the same, but storage is done through an indirection table.
    unsigned short indices[256];
    // Create reverse index mapping: write j-th result into position (255 - j)
    for (ssize_t idx = 0; idx < 256; idx++) {
        indices[idx] = (unsigned short)(255 - idx);
    }

    for (j = 0; j < 256; j++) {
        c = (unsigned char)j;
        count = 0;
        for (size_t mask = 0; mask < 8; mask++) {
            count += c & 1;
            c >>= 1;
        }
        // Write to permuted location
        bits[indices[j]] = (unsigned short)count;
    }
}
