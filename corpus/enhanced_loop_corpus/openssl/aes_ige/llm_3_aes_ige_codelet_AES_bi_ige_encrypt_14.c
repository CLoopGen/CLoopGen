#include <stdio.h>

#include <inttypes.h>

extern size_t n;
extern unsigned char tmp[16];
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access pattern)
    size_t indices[16] = { 0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7, 9, 11, 13, 15 }; // Even indices first, then odd
    for (size_t i = 0; i < 16; ++i) {
        size_t idx = indices[i];
        tmp[idx] ^= iv2[idx];
    }
}
