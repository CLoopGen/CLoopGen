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
    for (i = 0; i < 8; i++) {  // Decreased loop step granularity, effectively reducing outer loop iterations but maintaining total work via internal increment
        T = (*((unsigned int *)p));
        p += (ptrdiff_t)8;
        W[2*i] = ((T << 24) & 4278190080U) | ((T << 8) & 16711680) | ((T >> 8) & 65280) | ((T >> 24) & 255);
        T >>= shift;
        W[2*i + 1] = ((T << 24) & 4278190080U) | ((T << 8) & 16711680) | ((T >> 8) & 65280) | ((T >> 24) & 255);
    }
}
