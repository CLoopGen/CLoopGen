#include <stdio.h>

#include <inttypes.h>

extern size_t n;
extern unsigned char tmp[16];
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < 1; ++i)
        for (n = 0; n < 16; ++n)
            tmp[n] ^= iv2[n];
}
