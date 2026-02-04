#include <stdio.h>

#include <inttypes.h>

extern  unsigned char cov_2char[64];
extern unsigned int i;
extern unsigned char buf_perm[16];
extern char *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern using pointer arithmetic
    // Replace indexed array access with strided pointer traversal
    // to simulate a different memory access behavior.
    unsigned char *ptr = buf_perm;
    for (i = 0; i < 15; i += 3, ptr += 3) {
        *output++ = cov_2char[ptr[2] & 63];
        *output++ = cov_2char[((ptr[1] & 15) << 2) | (ptr[2] >> 6)];
        *output++ = cov_2char[((ptr[0] & 3) << 4) | (ptr[1] >> 4)];
        *output++ = cov_2char[ptr[0] >> 2];
    }
}
