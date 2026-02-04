#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_3x5[125];
extern int x1;
extern int x2;
extern int x3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering indices to traverse array in natural order
    int idx = 0;
    for (x1 = 0; x1 < 5; x1++)
        for (x2 = 0; x2 < 5; x2++)
            for (x3 = 0; x3 < 5; x3++) {
                mul_3x5[idx] = x1 + (x2 << 4) + (x3 << 8);
                idx++;
            }
}
