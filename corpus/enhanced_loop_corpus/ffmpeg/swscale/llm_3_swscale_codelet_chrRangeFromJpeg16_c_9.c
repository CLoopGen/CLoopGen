#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dstU;
extern int32_t *dstV;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = width - 1; i >= 0; i--) {
        dstU[i] = (dstU[i] * 1799 + (4081085 << 4)) >> 11;
        dstV[i] = (dstV[i] * 1799 + (4081085 << 4)) >> 11;
    }
}
