#include <stdio.h>

#include <inttypes.h>

extern unsigned char in[64];
extern size_t inlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from end to start
    for (i = inlen; i > 0; i--)
        in[i - 1] = (unsigned char)(i - 1);
}
