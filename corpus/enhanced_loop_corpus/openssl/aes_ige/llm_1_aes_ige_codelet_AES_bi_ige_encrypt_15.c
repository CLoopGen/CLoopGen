#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 4; ++n) {
        out[n] ^= iv[n];
        out[n + 4] ^= iv[n + 4];
        out[n + 8] ^= iv[n + 8];
        out[n + 12] ^= iv[n + 12];
    }
}
