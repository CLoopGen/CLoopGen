#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride
    // Modify access pattern to use a fixed stride of 3 instead of implicit stride 2 via doubling
    // Map index j to a strided position: x[3*j] and x[3*j - 1], maintaining data flow
    // This increases spacing between written values, altering cache behavior
    for (j = 100 - 1; j > 0; j--) {
        x[3 * j] = x[j];
        x[3 * j - 1] = 0;
    }
}
