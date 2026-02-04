#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_accum = 0;
    for (i = 0; i < width; i++) {
        int mixed = (b0[i] + b2[i] + 2 + local_accum); // Use accumulator to create loop-carried dependency
        local_accum = (int16_t)(mixed >> 1); // WAW-like anti-dependence avoided via private variable
        b1[i] = b1[i] - (unsigned int)(mixed >> 2); // Modify b1 only after using original value
    }
    // Final write-back or side effect not needed; loop semantics preserved via functional equivalence
}
