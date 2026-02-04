#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Modify access pattern to use a fixed stride (e.g., every 2nd element) across the array,
    // adjusting loop bounds and conditions accordingly. This introduces sparser, non-uniform memory access.
    // We keep the original logic but update j in larger steps and ensure alignment with original condition.

    for (j = 198; j >= 100; j -= 2) {  // Stride of 2
        if (((x[j]) & 1)) {
            // Ensure indices are within bounds for strided access
            int offset1 = 100 - 37;
            int offset2 = 100;
            if (j - offset1 >= 0)
                x[j - offset1] = (((x[j - offset1]) - (x[j])) & ((1L << 30) - 1));
            if (j - offset2 >= 0)
                x[j - offset2] = (((x[j - offset2]) - (x[j])) & ((1L << 30) - 1));
        }
    }
}
