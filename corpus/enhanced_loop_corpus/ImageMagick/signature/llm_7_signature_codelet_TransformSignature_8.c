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
unsigned int temp_W[2];
for (i = 0; i < 16; i += 2) {
    T = (*((unsigned int *)p));
    p += (ptrdiff_t)8;
    temp_W[0] = ((T << 24) & 4278190080U) | ((T << 8) & 16711680) | ((T >> 8) & 65280) | ((T >> 24) & 255);
    T >>= shift;
    temp_W[1] = ((T << 24) & 4278190080U) | ((T << 8) & 16711680) | ((T >> 8) & 65280) | ((T >> 24) & 255);
    W[i] = temp_W[0];
    W[i + 1] = temp_W[1];
}
}
