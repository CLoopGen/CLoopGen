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
for (i = 0; i < 8; i++) {
    T = (*((unsigned int *)p));
    p += (ptrdiff_t)4;
    W[i] = ((unsigned int)((T) & 4294967295U));
    W[i + 8] = ((unsigned int)(((T << 1) | (T >> 31)) & 4294967295U));
    W[i + 16] = ((unsigned int)(((T + 0xDEADBEEF) ^ 0xFFFFFFFFU) & 4294967295U));
    W[i + 24] = ((unsigned int)(((T * 3) + 0xCAFEBABE) & 4294967295U));
}
}
