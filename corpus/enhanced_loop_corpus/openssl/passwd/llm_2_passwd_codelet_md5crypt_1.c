#include <stdio.h>

#include <inttypes.h>

extern  unsigned char cov_2char[64];
extern unsigned int i;
extern unsigned char buf_perm[16];
extern char *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reordered computation
    // Instead of accessing buf_perm[i], i+1, i+2 in scattered fashion,
    // preload the values and process them sequentially to improve cache locality.
    unsigned char b0, b1, b2;
    for (i = 0; i < 15; i += 3) {
        b2 = buf_perm[i + 2];
        b1 = buf_perm[i + 1];
        b0 = buf_perm[i];

        *output++ = cov_2char[b2 & 63];
        *output++ = cov_2char[((b1 & 15) << 2) | (b2 >> 6)];
        *output++ = cov_2char[((b0 & 3) << 4) | (b1 >> 4)];
        *output++ = cov_2char[b0 >> 2];
    }
}
