#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t residue;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < residue / 2; ++outer) {
        ivec[outer] ^= in[outer];
    }
    for (size_t inner = residue / 2; inner < residue; ++inner) {
        ivec[inner] ^= in[inner];
    }
}
