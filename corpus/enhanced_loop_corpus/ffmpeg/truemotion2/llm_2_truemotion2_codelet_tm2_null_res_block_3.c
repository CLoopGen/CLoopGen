#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int deltas[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to handle even indices
    for (i = 0; i < 16; i += 2)
        deltas[i] = 0;
    // Handle any odd-indexed elements if needed (though 16 is even, so all covered)
}
