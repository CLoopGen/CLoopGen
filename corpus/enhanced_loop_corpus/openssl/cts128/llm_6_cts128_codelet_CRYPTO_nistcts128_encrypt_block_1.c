#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t residue;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (residue == 0) return;
    size_t i = 0;
    // Unroll by 2 to reduce loop-carried dependency and increase ILP
    for (; i < residue - 1; i += 2) {
        ivec[i] ^= in[i];
        ivec[i+1] ^= in[i+1];
    }
    // Handle leftover element
    if (i < residue) {
        ivec[i] ^= in[i];
    }
}
