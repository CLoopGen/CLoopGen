#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *lowband_out;
extern int i;
extern uint32_t N0;
extern float n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = N0 - 1; i >= 0; i--) {
        lowband_out[i] = n * X[i];
    }
}
