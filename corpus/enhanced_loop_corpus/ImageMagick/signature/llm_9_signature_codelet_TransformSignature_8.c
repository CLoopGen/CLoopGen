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
for (i = 0; i < 8; i += 2) {
    T = (*((unsigned int *)p));
    p += (ptrdiff_t)4;
    W[i] = (T << 24) | ((T << 8) & 16711680) | ((T >> 8) & 65280) | (T >> 24);
    T >>= shift;
    W[i + 1] = (T << 24) | ((T << 8) & 16711680) | ((T >> 8) & 65280) | (T >> 24);
}
}
