#include <stdio.h>

#include <inttypes.h>

extern size_t n;
extern unsigned char tmp[16];
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolling the loop to process two elements per iteration
    for (size_t i = 0; i < 16; i += 2) {
        tmp[i] ^= iv2[i];
        if (i + 1 < 16) {
            tmp[i + 1] ^= iv2[i + 1];
        }
    }
}
