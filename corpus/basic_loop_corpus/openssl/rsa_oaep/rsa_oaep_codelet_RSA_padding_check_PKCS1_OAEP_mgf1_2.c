#include <stdio.h>

#include <inttypes.h>

extern int i;
extern  unsigned char *maskedseed;
extern unsigned char seed[64];
extern int mdlen;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < mdlen; i++)
    seed[i] ^= maskedseed[i];

}
