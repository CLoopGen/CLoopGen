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
    if (srcSliceH <= 0) return;
    for (i = 0; i < srcSliceH; i++) {
        int offset = dstStride[0] * (srcSliceY + i);
        dstPtr[offset] = 255;
    }
}
