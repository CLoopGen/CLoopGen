#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    n = 0;
    for (size_t outer = 0; outer < 1; ++outer)
        for (; n < 16; ++n)
            out[n] ^= iv[n];
}
