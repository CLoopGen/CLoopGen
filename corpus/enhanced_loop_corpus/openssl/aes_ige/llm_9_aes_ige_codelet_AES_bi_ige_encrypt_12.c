#include <stdio.h>

#include <inttypes.h>

extern size_t n;
extern unsigned char tmp[16];
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < 32; ++i) {
        size_t idx = i % 16;
        tmp[idx] ^= iv2[idx] ^ (unsigned char)(i & 0xFF);
    }
}
