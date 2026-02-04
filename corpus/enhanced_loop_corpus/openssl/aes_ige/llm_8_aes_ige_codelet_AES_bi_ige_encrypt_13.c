#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 16; n += 2) {
        out[n] ^= iv[n] + 1;
        if (n + 1 < 16) {
            out[n + 1] ^= iv[n + 1] + 1;
        }
    }
}
