#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f[12];
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 1; i < 10 + 2; i += 2) {
        int val = f[i];
        int abs_val = (val >= 0) ? val : (-val);
        max = (max > abs_val) ? max : abs_val;
    }
}
