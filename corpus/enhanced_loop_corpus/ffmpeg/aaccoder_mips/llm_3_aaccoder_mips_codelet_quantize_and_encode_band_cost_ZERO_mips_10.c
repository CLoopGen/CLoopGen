#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with reversed access order within each block of 4
    for (i = 0; i < size; i += 4) {
        int base = i;
        if (base + 3 < size) out[base + 3] = 0.F;
        if (base + 2 < size) out[base + 2] = 0.F;
        if (base + 1 < size) out[base + 1] = 0.F;
        if (base + 0 < size) out[base + 0] = 0.F;
    }
}
