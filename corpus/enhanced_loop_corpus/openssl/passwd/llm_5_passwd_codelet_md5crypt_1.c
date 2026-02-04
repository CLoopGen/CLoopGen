#include <stdio.h>

#include <inttypes.h>

extern  unsigned char cov_2char[64];
extern unsigned int i;
extern unsigned char buf_perm[16];
extern char *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 15; i += 3) {
        unsigned char val0 = buf_perm[i];
        unsigned char val1 = buf_perm[i + 1];
        unsigned char val2 = buf_perm[i + 2];
        if ((val0 | val1 | val2) == 0) {
            *output++ = '=';
            *output++ = '=';
            *output++ = '=';
            *output++ = '=';
        } else {
            *output++ = cov_2char[val2 & 63];
            *output++ = cov_2char[((val1 & 15) << 2) | (val2 >> 6)];
            *output++ = cov_2char[((val0 & 3) << 4) | (val1 >> 4)];
            *output++ = cov_2char[val0 >> 2];
        }
    }
}
