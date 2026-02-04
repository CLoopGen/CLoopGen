#include <stdio.h>

#include <inttypes.h>

extern size_t n;
extern unsigned char tmp[16];
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 16; ++n) {
        tmp[n] ^= (n % 2 == 0) ? iv2[n] : 0;
    }
}
