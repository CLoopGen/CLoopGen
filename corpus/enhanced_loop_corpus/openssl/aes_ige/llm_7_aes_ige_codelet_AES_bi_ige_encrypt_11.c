#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char prev = 0;
    for (n = 0; n < 16; ++n) {
        unsigned char current = out[n] ^ iv2[n] ^ prev;
        out[n] = current;
        prev = current;
    }
}
