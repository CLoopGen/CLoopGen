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
    p += (ptrdiff_t)8;
    W[i] = ((unsigned int)((T >> shift) & 4294967295U));
    W[i + 1] = ((unsigned int)((T) & 4294967295U));
}

}
