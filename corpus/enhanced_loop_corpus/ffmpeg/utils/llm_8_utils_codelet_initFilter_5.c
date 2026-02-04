#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **filterPos;
extern int xInc;
extern int dstW;
extern int filterSize;
extern int64_t *filter;
extern  int64_t fone;
extern int i;
extern int64_t xDstInSrc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = (filterSize - 1) << 15;
    int round = (1 << 15);
    int shift = 16;
    // Remove loop-carried dependency on xDstInSrc by computing directly from i
    for (i = 0; i < dstW; i++) {
        int64_t temp_xSrc = xDstInSrc + (int64_t)i * xInc;  // Eliminate update, compute directly
        int xx = (temp_xSrc - offset + round) >> shift;
        (*filterPos)[i] = xx;
        filter[i] = fone;
        // No mutation to xDstInSrc inside loop — removed loop-carried dependency (RAW)
    }
    // Final value of xDstInSrc not updated — side effect removed for independence
}
