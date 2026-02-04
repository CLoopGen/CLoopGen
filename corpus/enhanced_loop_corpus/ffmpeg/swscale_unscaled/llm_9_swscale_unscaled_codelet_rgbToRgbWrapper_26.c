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
    for (i = 0; i < srcSliceH; i++) {
        int index = dstStride[0] * (srcSliceY + i);
        for (j = 0; j < 3; j++) {
            dstPtr[index + j] = (j % 2) ? 128 : 255;
        }
    }
}
