#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-sequential access pattern
    size_t indices[16] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // Reverse order access
    for (n = 0; n < 16; ++n) {
        size_t idx = indices[n];
        out[idx] ^= iv[idx];
    }
}
