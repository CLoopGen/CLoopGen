#include <stdio.h>

#include <inttypes.h>

extern unsigned char in[64];
extern size_t inlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < inlen; i += 2) {
        if (i + 1 < inlen) {
            in[i] = (unsigned char)(i * 2);
            in[i + 1] = (unsigned char)((i + 1) * 2);
        } else {
            in[i] = (unsigned char)(i * 2);
        }
    }
}
