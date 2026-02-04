#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t residue;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char local_ivec[16] = {0};
    for (n = 0; n < residue; ++n)
        local_ivec[n] = ivec[n] ^ in[n];
    for (n = 0; n < residue; ++n)
        ivec[n] = local_ivec[n];
}
