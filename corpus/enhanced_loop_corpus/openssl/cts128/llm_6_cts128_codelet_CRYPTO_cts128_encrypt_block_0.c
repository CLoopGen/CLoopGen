#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t residue;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (residue > 0) {
        unsigned char temp = ivec[0];
        for (n = 0; n < residue; ++n) {
            temp ^= in[n];
            ivec[n] = temp;
        }
    }
}
