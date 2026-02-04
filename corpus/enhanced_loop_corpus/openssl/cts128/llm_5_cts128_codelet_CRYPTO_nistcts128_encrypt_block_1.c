#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t residue;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < residue && residue > 8; ++n) {
        if (n >= 16) break;
        ivec[n] ^= in[n];
    }
}
