#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int srcSliceY;
extern int srcSliceH;
extern int dstStride[];
extern uint8_t *dstPtr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic
    uint8_t *ptr = &dstPtr[dstStride[0] * srcSliceY];
    int stride = dstStride[0];
    for (i = 0; i < srcSliceH; i++) {
        *ptr = 255;
        ptr += stride;
    }
}
