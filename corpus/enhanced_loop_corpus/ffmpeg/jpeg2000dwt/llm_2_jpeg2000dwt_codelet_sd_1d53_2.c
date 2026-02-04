#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing p[2*i], p[2*i+1], p[2*i+2] (strided by 2), 
    // rewrite the loop to traverse elements consecutively using a pointer.
    int *base = p + ((i0 + 1) & ~1); // Align to even index: 2*((i0+1)>>1)
    int count = ((i1 + 1) >> 1) - ((i0 + 1) >> 1);
    for (i = 0; i < count; i++) {
        base[2*i + 1] -= (base[2*i] + base[2*i + 2]) >> 1;
    }
}
