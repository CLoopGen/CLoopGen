#include <stdio.h>

#include <inttypes.h>

extern  unsigned char cov_2char[64];
extern unsigned int i;
extern unsigned char buf_perm[16];
extern char *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 15; i += 3) {
        unsigned char val_i = buf_perm[i];
        unsigned char val_i1 = buf_perm[i + 1];
        unsigned char val_i2 = buf_perm[i + 2];
        *output++ = cov_2char[val_i2 >> 2];
        *output++ = cov_2char[((val_i1 & 15) << 2) | (val_i2 & 63)];
        *output++ = cov_2char[(val_i & 3) << 4 | (val_i1 >> 4)];
        *output++ = cov_2char[val_i >> 2];
    }
}
