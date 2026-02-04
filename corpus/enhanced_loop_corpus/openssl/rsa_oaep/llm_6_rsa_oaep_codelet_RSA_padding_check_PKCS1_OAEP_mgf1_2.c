#include <stdio.h>

#include <inttypes.h>

extern int i;
extern  unsigned char *maskedseed;
extern unsigned char seed[64];
extern int mdlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp;
    for (i = 0; i < mdlen; i++) {
        temp = maskedseed[i];
        seed[i] ^= temp;
    }
}
