#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long Nc;
extern int *jE;
extern int *jW;
extern long j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using reversed index order
    for (j = 0; j < Nc; j++) {
        long idx = Nc - 1 - j;  // Reverse the access pattern
        jW[idx] = idx - 1;
        jE[idx] = idx + 1;
    }
}
