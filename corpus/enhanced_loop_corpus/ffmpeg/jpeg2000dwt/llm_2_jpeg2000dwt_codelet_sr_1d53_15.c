#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    unsigned int *base = p + (i0 & ~1);  // Align to even index corresponding to i0 >> 1
    int count = (i1 >> 1) - (i0 >> 1);
    for (int j = 0; j < count; j++) {
        base[2*j + 1] += (int)(base[2*j] + base[2*j + 2]) >> 1;
    }
}
