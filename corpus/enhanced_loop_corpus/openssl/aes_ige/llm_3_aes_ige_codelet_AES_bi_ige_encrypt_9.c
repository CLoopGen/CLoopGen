#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access — traverse arrays from the end to the beginning
    for (size_t n = 15; ; --n) {
        out[n] ^= iv2[n];
        if (n == 0) break;
    }
}
