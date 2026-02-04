#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (unrolled-like pattern)
    // Access elements in a strided manner, still initializing to zero
    for (j = 1; j <= 4; j += 2) {
        ctot[j - 1] = 0;
        if (j + 1 <= 4) {
            ctot[j] = 0;
        }
    }
}
