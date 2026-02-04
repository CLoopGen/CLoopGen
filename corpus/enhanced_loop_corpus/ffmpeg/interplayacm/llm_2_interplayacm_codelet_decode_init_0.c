#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_3x3[27];
extern int x1;
extern int x2;
extern int x3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using a single index variable
    int idx = 0;
    for (int x3 = 0; x3 < 3; x3++)
        for (int x2 = 0; x2 < 3; x2++)
            for (int x1 = 0; x1 < 3; x1++, idx++)
                mul_3x3[idx] = x1 + (x2 << 4) + (x3 << 8);
}
