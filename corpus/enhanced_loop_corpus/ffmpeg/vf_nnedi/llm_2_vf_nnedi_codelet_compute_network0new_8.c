#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float vals[8];
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order
    for (i = 3; i >= 0; i--) {
        if (vals[i + 4] > 0.F)
            mask |= (1 << (i << 3));
    }
}
