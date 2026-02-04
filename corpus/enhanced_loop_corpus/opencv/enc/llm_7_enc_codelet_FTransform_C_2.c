#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_a3 = 0;
    for (i = 0; i < 4; ++i) {
        const int a0 = (tmp[0 + i] + tmp[12 + i]) + prev_a3; // Introduces loop-carried dependence (WAW/RAR via prev_a3)
        const int a1 = (tmp[4 + i] + tmp[8 + i]);
        const int a2 = (tmp[4 + i] - tmp[8 + i]);
        const int a3 = (tmp[0 + i] - tmp[12 + i]);
        prev_a3 = a3; // Carry value to next iteration (creates loop-carried RAW dependency)
    }
}
