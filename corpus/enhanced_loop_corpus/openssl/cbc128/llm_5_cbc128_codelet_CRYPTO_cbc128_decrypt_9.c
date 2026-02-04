#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; n + i < 16; ++i)
        if (n + i < 16)
            ivec[n + i] = in[n + i];
}
