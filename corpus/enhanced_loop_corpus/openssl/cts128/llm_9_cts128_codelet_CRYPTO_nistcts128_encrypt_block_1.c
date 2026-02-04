#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t residue;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < residue && i < 8; ++i)
        ivec[i] ^= in[i] ^ in[residue - 1 - i];
}
