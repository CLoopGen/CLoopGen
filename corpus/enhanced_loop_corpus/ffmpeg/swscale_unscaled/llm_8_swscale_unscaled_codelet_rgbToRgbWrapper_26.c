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
    for (i = 0; i < srcSliceH; i += 2) {
        if (srcSliceY + i < 1024) {
            dstPtr[dstStride[0] * (srcSliceY + i)] = 255;
            dstPtr[dstStride[0] * (srcSliceY + i + 1)] = 255;
        }
    }
}
