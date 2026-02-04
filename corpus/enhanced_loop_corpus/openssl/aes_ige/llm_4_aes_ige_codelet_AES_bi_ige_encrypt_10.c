#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 16; ++n) {
        if (iv[n] != 0)
            out[n] ^= iv[n];
    }
}
