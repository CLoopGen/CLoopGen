#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t residue;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < residue * 2; i += 2) {
        size_t idx = i / 2;
        if (idx < residue) {
            ivec[idx] ^= in[idx] + (in[idx] >> 1) - (in[idx] << 1);
        }
    }
}
