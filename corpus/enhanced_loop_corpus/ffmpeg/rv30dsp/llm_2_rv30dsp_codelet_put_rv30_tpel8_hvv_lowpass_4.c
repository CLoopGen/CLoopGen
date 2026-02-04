#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int h;
extern  uint8_t *cm;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    uint8_t *src_row = src;
    uint8_t *dst_row = dst;
    for (int j = 0; j < h; j++) {
        uint8_t *src_p = src_row - srcStride + 1; // Point to i-1 of previous row
        for (int i = 0; i < w; i++) {
            int val = (src_p[-srcStride - 1] - 12 * src_p[-srcStride] - 6 * src_p[-srcStride + 1] + src_p[-srcStride + 2]
                     - 6 * src_p[-1] + 72 * src_p[0] + 36 * src_p[1] - 6 * src_p[2]
                     - 12 * src_p[srcStride - 1] + 144 * src_p[srcStride] + 72 * src_p[srcStride + 1] - 12 * src_p[srcStride + 2]
                     + src_p[2*srcStride - 1] - 12 * src_p[2*srcStride] - 6 * src_p[2*srcStride + 1] + src_p[2*srcStride + 2] + 128) >> 8;
            dst_row[i] = cm[val];
            src_p++;
        }
        src_row += srcStride;
        dst_row += dstStride;
    }
}
