#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src[];
extern int srcStride[];
extern uint8_t *dst;
extern int dstStride;
extern int srcSliceH;
extern int alpha_first;
extern int width;
extern int x;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (h = 0; h < srcSliceH; h++) {
        uint8_t *dest = dst + dstStride * h;
        int x = 0;
        // Removed conditional branch by precomputing index order based on alpha_first
        const int idx0 = alpha_first ? 3 : 0;
        const int idx1 = alpha_first ? 0 : 1;
        const int idx2 = alpha_first ? 1 : 2;
        const int idx3 = alpha_first ? 2 : 3;

        for (; x < width; x++) {
            *dest++ = src[idx0][x];
            *dest++ = src[idx1][x];
            *dest++ = src[idx2][x];
            *dest++ = src[idx3][x];
        }

        for (i = 0; i < 4; i++)
            src[i] += srcStride[i];
    }
}
