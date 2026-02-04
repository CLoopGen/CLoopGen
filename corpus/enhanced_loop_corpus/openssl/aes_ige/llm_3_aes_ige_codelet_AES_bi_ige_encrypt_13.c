#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access – traverse array from end to start
    for (n = 15; n < 16 && n >= 0; --n) {
        out[n] ^= iv[n];
    }
}
