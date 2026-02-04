#include <stdio.h>

#include <inttypes.h>

extern  unsigned char cov_2char[64];
extern unsigned int i;
extern unsigned char buf_perm[16];
extern char *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp1, temp2, temp3, temp4;
    for (i = 0; i < 15; i += 3) {
        temp1 = buf_perm[i + 2] & 63;
        temp2 = ((buf_perm[i + 1] & 15) << 2) | (buf_perm[i + 2] >> 6);
        temp3 = ((buf_perm[i] & 3) << 4) | (buf_perm[i + 1] >> 4);
        temp4 = buf_perm[i] >> 2;
        *output++ = cov_2char[temp1];
        *output++ = cov_2char[temp2];
        *output++ = cov_2char[temp3];
        *output++ = cov_2char[temp4];
    }
}
