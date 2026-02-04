#include <stdio.h>

#include <inttypes.h>

extern unsigned char in[64];
extern size_t inlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < inlen; i++)
    in[i] = (unsigned char)i;

}
