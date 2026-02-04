#include <stdio.h>

#include <inttypes.h>

extern size_t n;
extern unsigned char tmp[16];
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n < 16; ++n)
        tmp[n] ^= tmp[n-1] ^ iv2[n];
}
