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
    for (i = 0; i < 32; i += 4) {
        T = (*((unsigned int *)p));
        p += (ptrdiff_t)16;
        W[i] = ((unsigned int)((T >> shift) & 4294967295U));
        W[i + 1] = ((unsigned int)(T & 4294967295U));
        W[i + 2] = ((unsigned int)((T >> (shift + 1)) & 4294967295U));
        W[i + 3] = ((unsigned int)((T << 1) & 4294967295U));
    }
}
