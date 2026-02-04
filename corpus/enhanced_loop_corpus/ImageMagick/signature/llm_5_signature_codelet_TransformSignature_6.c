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
for (i = 0; i < 16; ++i) {
    T = (*((unsigned int *)p));
    p += (ptrdiff_t)4;
    if (i % 2 == 0) {
        W[i] = ((unsigned int)((T >> shift) & 4294967295U));
    } else {
        W[i] = ((unsigned int)(T & 4294967295U));
    }
    p += (ptrdiff_t)4;
}
}
