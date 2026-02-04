#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *p;
extern unsigned int T;
extern unsigned int W[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        T = (*((unsigned int *)p));
        W[i] = ((unsigned int)((T) & 4294967295U));
        p += (ptrdiff_t)4;
    }
}
