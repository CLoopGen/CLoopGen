#include <stdio.h>

#include <inttypes.h>

extern int i;
extern  unsigned char *maskedseed;
extern unsigned char seed[64];
extern int mdlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (mdlen > 0) {
        seed[0] ^= maskedseed[0];
        for (i = 1; i < mdlen; i++) {
            seed[i] ^= maskedseed[i] ^ seed[i-1];
        }
    }
}
