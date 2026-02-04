#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; n < 16 && i < 1; ++i)
        for (; n < 16; ++n)
            out[n] = iv[n];
}
