#include <stdio.h>

#include <inttypes.h>

extern long x;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = n = 0; x && (i < (sizeof(long) * 8 - 1)); ++i, x >>= 2) {
        n += (int)(x & 1L);
        n += (int)((x >> 1) & 1L);  // Process two bits per iteration
    }
    // Handle leftover bit if any
    if (x && (i == (sizeof(long) * 8 - 1)))
        n += (int)(x & 1L);
}
