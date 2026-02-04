#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-sequential access
    size_t indices[16] = {0,2,4,6,8,10,12,14,1,3,5,7,9,11,13,15}; // Even indices first, then odd
    for (n = 0; n < 16; ++n) {
        size_t idx = indices[n];
        out[idx] ^= iv[idx];
    }
}
