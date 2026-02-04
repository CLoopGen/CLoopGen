#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char acc = 0;
    for (n = 0; n < 16; ++n) {
        acc ^= iv2[n];
        out[n] ^= acc;
    }
}
