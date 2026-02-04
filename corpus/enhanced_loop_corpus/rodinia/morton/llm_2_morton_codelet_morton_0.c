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
    // Variant 1: Strided memory access with increased stride (access every 2nd element)
    for (b = 0; b < 16; b += 2) {
        int index = b * 2;
        *(x + index) |= (i & (1 << (index))) >> b;
        *(y + index) |= (i & (1 << (index + 1))) >> (b + 1);
    }
}
