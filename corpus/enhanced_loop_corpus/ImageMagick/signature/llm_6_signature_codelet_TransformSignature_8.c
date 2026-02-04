#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *p;
extern unsigned int shift;
extern unsigned int T;
extern unsigned int W[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i += 2) {
    T = (*((unsigned int *)p));
    unsigned int T_shifted = T >> shift;
    p += (ptrdiff_t)8;
    W[i] = ((T << 24) & 4278190080U) | ((T << 8) & 16711680) | ((T >> 8) & 65280) | ((T >> 24) & 255);
    W[i + 1] = ((T_shifted << 24) & 4278190080U) | ((T_shifted << 8) & 16711680) | ((T_shifted >> 8) & 65280) | ((T_shifted >> 24) & 255);
}
}
