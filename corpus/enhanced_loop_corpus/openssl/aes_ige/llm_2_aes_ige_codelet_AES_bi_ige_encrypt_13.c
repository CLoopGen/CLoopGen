#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    for (n = 0; n < 16; n += 2) {
        out[n] ^= iv[n];
        if (n + 1 < 16) {
            out[n + 1] ^= iv[n + 1];
        }
    }
}
