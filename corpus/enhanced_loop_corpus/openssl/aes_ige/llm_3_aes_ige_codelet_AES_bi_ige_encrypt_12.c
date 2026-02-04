#include <stdio.h>

#include <inttypes.h>

extern size_t n;
extern unsigned char tmp[16];
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse-order memory access — traverse arrays from last to first element
    for (size_t n = 15; ; --n) {
        tmp[n] ^= iv2[n];
        if (n == 0) break;
    }
}
