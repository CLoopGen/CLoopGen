#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *x;
extern int *y;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (b = 0; b < 8; b++) {
    int shift1 = b * 2;
    int shift2 = shift1 + 1;
    *x |= ((i & (1 << shift1)) >> b);
    *y |= ((i & (1 << shift2)) >> (b + 1));
    
    // Add additional computational work per iteration
    *x ^= (i >> (shift1 + 3)) & 0x1;
    *y ^= (i >> (shift2 + 4)) & 0x1;
}
}
