#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    size_t i;
    for (i = 0; i < 16; i += 2) {
        out[i] ^= iv2[i];
        if (i + 1 < 16) {
            out[i + 1] ^= iv2[i + 1];
        }
    }
}
