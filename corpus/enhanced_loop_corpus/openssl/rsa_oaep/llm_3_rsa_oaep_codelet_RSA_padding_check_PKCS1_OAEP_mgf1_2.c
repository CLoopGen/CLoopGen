#include <stdio.h>

#include <inttypes.h>

extern int i;
extern  unsigned char *maskedseed;
extern unsigned char seed[64];
extern int mdlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access — traverse the array from the end to the beginning
    for (i = mdlen - 1; i >= 0; i--) {
        seed[i] ^= maskedseed[i];
    }
}
