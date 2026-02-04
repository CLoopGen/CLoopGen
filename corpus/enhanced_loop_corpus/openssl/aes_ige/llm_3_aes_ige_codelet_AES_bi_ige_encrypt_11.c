#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-sequential access pattern
    static const size_t indices[16] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0}; // Reverse order access
    size_t i;
    for (i = 0; i < 16; ++i) {
        size_t idx = indices[i];
        out[idx] ^= iv2[idx];
    }
}
