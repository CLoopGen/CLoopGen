#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_2x11[121];
extern int x1;
extern int x2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride and sequential index progression
    int idx = 0;
    for (x2 = 0; x2 < 11; x2++) {
        for (x1 = 0; x1 < 11; x1++) {
            mul_2x11[idx] = x1 + (x2 << 4);
            idx += 2; // Stride of 2 for non-consecutive storage
        }
    }
}
