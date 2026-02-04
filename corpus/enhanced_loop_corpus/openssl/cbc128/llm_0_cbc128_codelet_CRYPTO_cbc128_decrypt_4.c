#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < 16; ++i)
        for (size_t j = 0; j < 1; ++j)
            out[i] ^= iv[i];
}
