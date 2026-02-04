#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 32; ++n) {
        size_t index = n % 16;
        out[index] ^= iv[index] ^ (unsigned char)(n >> 4);
    }
}
