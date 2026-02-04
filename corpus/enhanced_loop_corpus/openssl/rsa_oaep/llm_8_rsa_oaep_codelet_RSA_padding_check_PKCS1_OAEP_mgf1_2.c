#include <stdio.h>

#include <inttypes.h>

extern int i;
extern  unsigned char *maskedseed;
extern unsigned char seed[64];
extern int mdlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < mdlen * 2; i += 2) {
        j = i % 64;
        seed[j] ^= maskedseed[j];
        if (i + 1 < mdlen * 2) {
            j = (i + 1) % 64;
            seed[j] ^= maskedseed[j];
        }
    }
}
