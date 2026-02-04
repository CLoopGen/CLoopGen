#include <stdio.h>

#include <inttypes.h>

extern long x;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = n = 0; i < (sizeof(long) * 8); ++i, x >>= 1) {
        if (!x) break;
        n += (int)(x & 1L);
    }
}
