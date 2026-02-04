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
    int offset;
    for (i = 0; i < srcSliceH; i++) {
        offset = dstStride[0] * (srcSliceY + (srcSliceH - 1 - i)); // Reverse access order
        dstPtr[offset] = 255;
        if (i > 0) {
            dstPtr[offset] += dstPtr[dstStride[0] * (srcSliceY + i - 1)]; // RAW: current depends on previous iteration's location
        }
    }
}
