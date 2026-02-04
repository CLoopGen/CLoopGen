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
    unsigned int indices[8] = {0, 2, 4, 6, 8, 10, 12, 14};
    for (i = 0; i < 8; ++i) {
        ptrdiff_t offset = (ptrdiff_t)(indices[i] * 8);
        T = *((unsigned int *)(p + offset));
        W[indices[i]] = (unsigned int)((T >> shift) & 4294967295U);
        W[indices[i] + 1] = (unsigned int)(T & 4294967295U);
    }
}
