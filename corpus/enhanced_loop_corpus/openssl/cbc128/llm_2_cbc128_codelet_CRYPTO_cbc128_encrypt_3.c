#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    // This changes sequential access to strided access, skipping every other element in both arrays
    for (size_t i = 0; i < 16; i += 2) {
        out[i] = iv[i];
    }
}
