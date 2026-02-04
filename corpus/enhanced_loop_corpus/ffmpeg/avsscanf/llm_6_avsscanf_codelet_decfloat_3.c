#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int i;
extern int a;
extern int z;
extern double y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = i = 0; i < 2; i++) {
        uint32_t temp = x[a + i & (128 - 1)];
        if ((a + i & (128 - 1)) == z) {
            z = (z + 1 & (128 - 1));
            x[z - 1] = i; // Introduce WAW dependency across iterations via x[z-1], and use loop index
        }
        y = 1.0E+9L * y + temp + (i > 0 ? x[(a + i - 1) & (128 - 1)] : 0); // Add RAW: current depends on previous x value
    }
}
