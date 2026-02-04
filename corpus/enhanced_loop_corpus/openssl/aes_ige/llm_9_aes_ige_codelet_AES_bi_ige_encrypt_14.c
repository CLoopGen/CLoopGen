#include <stdio.h>

#include <inttypes.h>

extern size_t n;
extern unsigned char tmp[16];
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 32; n += 2)
        tmp[n % 16] ^= iv2[n % 16];
}
