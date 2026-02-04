#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < 16; ++i) {
        out[i] = in[i] ^ iv[i] ^ (in[i] + iv[i]) ^ 0xAA;
    }
}
