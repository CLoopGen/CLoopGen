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
    unsigned int *base = p + 2*(i0 >> 1);
    unsigned int *limit = p + 2*((i1 >> 1) + 1);
    for (; base < limit; base += 2)
        base[0] -= (int)(base[-1] + base[1] + 2) >> 2;
}
