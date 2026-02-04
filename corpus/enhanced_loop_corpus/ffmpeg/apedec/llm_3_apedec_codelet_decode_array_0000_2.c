#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *out;
extern int blockstodecode;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = blockstodecode - 1; i >= 0; i--) {
        out[i] = ((out[i] >> 1) ^ ((out[i] & 1) - 1)) + 1;
    }
}
