#include <stdio.h>

#include <inttypes.h>

extern unsigned char in[64];
extern size_t inlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp[64];
    for (i = 0; i < inlen; i++) {
        temp[i] = (unsigned char)(i + 1);
        in[i] = temp[i];
    }
}
