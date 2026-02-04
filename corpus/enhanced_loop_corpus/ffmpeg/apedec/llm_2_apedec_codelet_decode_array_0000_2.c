#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *out;
extern int blockstodecode;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (forward strided)
    for (i = 0; i < blockstodecode; i += 2) {
        if (i < blockstodecode) {
            out[i] = ((out[i] >> 1) ^ ((out[i] & 1) - 1)) + 1;
        }
    }
}
