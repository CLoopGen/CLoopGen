#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_2x11[121];
extern int x1;
extern int x2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by swapping loop order for row-major traversal
    for (x1 = 0; x1 < 11; x1++)
        for (x2 = 0; x2 < 11; x2++)
            mul_2x11[x2 + x1 * 11] = x1 + (x2 << 4);
}
