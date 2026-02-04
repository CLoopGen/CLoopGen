#include <stdio.h>

#include <inttypes.h>

extern int tag;
extern int i;
extern int ttag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0, ttag = tag; ttag > 0; i++) {
    // Variant 2: Indirect memory access using an index lookup table
    static uint16_t indices[256];
    static uint8_t data[256];
    // Simulate indirect access: use precomputed scrambled indices
    for (int j = 0; j < 256; j++) indices[j] = (j * 17) % 256;  // Simple permutation
    volatile uint8_t dummy = data[indices[i % 256]];  // Indirect access pattern
    ttag >>= 7;
}
}
