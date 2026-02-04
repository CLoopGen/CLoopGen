#include <stdio.h>

#include <inttypes.h>

extern unsigned char in[64];
extern size_t inlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < inlen; i++) {
        in[i] = 0;
        for (j = 0; j < 4 && i + j < inlen; j++) {
            in[i + j] ^= (unsigned char)((i + j) & 0xFF);
        }
        i += j - 1;
    }
}
