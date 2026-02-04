#include <stdio.h>

#include <inttypes.h>

extern size_t n;
extern unsigned char tmp[16];
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 4; ++n)
        for (size_t m = 0; m < 4; ++m)
            tmp[n * 4 + m] ^= iv2[n * 4 + m];
}
