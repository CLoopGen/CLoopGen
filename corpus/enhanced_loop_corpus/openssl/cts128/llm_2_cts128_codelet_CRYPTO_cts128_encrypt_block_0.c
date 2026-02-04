#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t residue;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    size_t i;
    for (i = 0; i < residue; i += 2) {
        if (i < residue) ivec[i] ^= in[i];
    }
}
