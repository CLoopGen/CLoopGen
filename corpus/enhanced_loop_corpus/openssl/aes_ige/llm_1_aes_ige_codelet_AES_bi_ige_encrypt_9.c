#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 4; ++n) {
        out[n +  0] ^= iv2[n +  0];
        out[n +  4] ^= iv2[n +  4];
        out[n +  8] ^= iv2[n +  8];
        out[n + 12] ^= iv2[n + 12];
    }
}
