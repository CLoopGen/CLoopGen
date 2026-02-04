#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float vals[8];
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using a step of 2, processing alternating elements
    for (i = 0; i < 4; i += 2) {
        int idx = 4 + i;
        if (vals[idx] > 0.F)
            mask |= (1 << (i << 3));
        if (i + 1 < 4 && vals[idx + 1] > 0.F)
            mask |= (1 << ((i + 1) << 3));
    }
}
