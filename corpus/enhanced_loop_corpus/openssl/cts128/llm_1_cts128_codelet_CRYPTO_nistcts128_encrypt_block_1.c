#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t residue;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < residue / 16 + !!(residue % 16); ++outer) {
        for (size_t inner = 0; inner < 16; ++inner) {
            size_t idx = outer * 16 + inner;
            if (idx < residue) {
                ivec[idx] ^= in[idx];
            }
        }
    }
}
