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
    unsigned int temp_T[2];
    for (i = 0; i < 16; i += 2) {
        temp_T[0] = (*((unsigned int *)p));
        temp_T[1] = (*((unsigned int *)(p + 4)));
        p += (ptrdiff_t)8;
        W[(i + 1) % 16] = ((unsigned int)((temp_T[0] >> shift) & 4294967295U));
        W[i] = ((unsigned int)(temp_T[1] & 4294967295U));
    }
}
