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
    for (b = 0; b < 16; b++) {
        int shift1 = b * 2;
        int shift2 = b * 2 + 1;
        int mask1 = 1 << shift1;
        int mask2 = 1 << shift2;
        int val1 = (i & mask1) >> b;
        int val2 = (i & mask2) >> (b + 1);
        *x |= val1;
        *y |= val2;
    }
}
