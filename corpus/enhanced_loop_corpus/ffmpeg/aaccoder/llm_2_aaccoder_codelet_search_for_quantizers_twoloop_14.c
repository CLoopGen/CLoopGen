#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int maxsf[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < sizeof(maxsf) / sizeof(maxsf[0]); i += 2) {
        maxsf[i] = 255;
    }
    // Fill remaining odd indices in a second pass to maintain correctness
    for (i = 1; i < sizeof(maxsf) / sizeof(maxsf[0]); i += 2) {
        maxsf[i] = 255;
    }
}
