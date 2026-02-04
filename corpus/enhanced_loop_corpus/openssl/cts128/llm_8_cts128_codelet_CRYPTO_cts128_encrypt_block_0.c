#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t residue;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < residue; i += 2) {
        if (i + 1 < residue) {
            ivec[i] ^= in[i];
            ivec[i + 1] ^= in[i + 1];
        } else {
            ivec[i] ^= in[i];
        }
    }
}
