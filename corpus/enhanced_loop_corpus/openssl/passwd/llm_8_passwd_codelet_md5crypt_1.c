#include <stdio.h>

#include <inttypes.h>

extern  unsigned char cov_2char[64];
extern unsigned int i;
extern unsigned char buf_perm[16];
extern char *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 15; i += 3) {
        unsigned char b0 = buf_perm[i];
        unsigned char b1 = buf_perm[i + 1];
        unsigned char b2 = buf_perm[i + 2];
        *output++ = cov_2char[b2 & 63];
        *output++ = cov_2char[((b1 & 15) << 2) | (b2 >> 6)];
        *output++ = cov_2char[((b0 & 3) << 4) | (b1 >> 4)];
        *output++ = cov_2char[b0 >> 2];
    }
}
