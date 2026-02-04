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
    int j;
    uint8_t temp = 0;
    for (i = 0; i < srcSliceH; i++) {
        j = dstStride[0] * (srcSliceY + i);
        temp += dstPtr[j]; // Introduce RAW dependency: use previous value
        dstPtr[j] = temp;  // WAW: temp is reused, but not across iterations directly
        temp = 255;        // Remove cumulative dependency; reset to break loop-carried dep on temp
    }
}
