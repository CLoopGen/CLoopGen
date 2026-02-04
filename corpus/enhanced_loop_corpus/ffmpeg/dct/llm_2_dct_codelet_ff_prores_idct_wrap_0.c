#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*qmat);
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 64; i += 2) {
        qmat[i] = 4;
    }
    // Fill the odd indices in a second pass to maintain all 64 elements set to 4
    for (i = 1; i < 64; i += 2) {
        qmat[i] = 4;
    }
}
