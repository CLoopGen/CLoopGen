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
    ptrdiff_t indices[16];
    for (ssize_t idx = 0; idx < 16; idx++) {
        indices[idx] = idx * 2;
    }
    for (i = 0; i < 16; i += 2) {
        ptrdiff_t offset = indices[i];
        T = *((unsigned int *)(p + offset * 4));
        p += (ptrdiff_t)8; // Maintain pointer progression for realism
        W[indices[i]] = ((T << 24) & 4278190080U) | ((T << 8) & 16711680) | ((T >> 8) & 65280) | ((T >> 24) & 255);
        T >>= shift;
        W[indices[i] + 1] = ((T << 24) & 4278190080U) | ((T << 8) & 16711680) | ((T >> 8) & 65280) | ((T >> 24) & 255);
    }
}
