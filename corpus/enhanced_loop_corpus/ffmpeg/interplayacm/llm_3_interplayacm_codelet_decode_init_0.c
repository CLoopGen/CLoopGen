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
    // Variant 2: Strided memory access with reversed loop order (access by x1 stride)
    for (int x1 = 0; x1 < 3; x1++)
        for (int x2 = 0; x2 < 3; x2++)
            for (int x3 = 0; x3 < 3; x3++)
                mul_3x3[x1 * 9 + x2 * 3 + x3] = x1 + (x2 << 4) + (x3 << 8);
}
