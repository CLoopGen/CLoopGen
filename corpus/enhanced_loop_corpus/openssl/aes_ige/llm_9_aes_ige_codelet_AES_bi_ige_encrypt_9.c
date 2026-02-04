#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < 32; ++i) {
        size_t idx = i % 16;
        out[idx] ^= iv2[idx] ^ (unsigned char)(i >> 4);
    }
}
