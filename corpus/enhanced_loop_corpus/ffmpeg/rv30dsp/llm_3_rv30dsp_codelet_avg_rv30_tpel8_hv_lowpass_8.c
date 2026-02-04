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
for (j = 0; j < h; j++) {
    for (i = 0; i < w; i++) {
        // Change memory access to use linear index with precomputed base offsets
        int src_center = j * srcStride + i;
        int neighbors[16] = {
            src_center - srcStride - 1, src_center - srcStride, src_center - srcStride + 1, src_center - srcStride + 2,
            src_center - 1, src_center, src_center + 1, src_center + 2,
            src_center + srcStride - 1, src_center + srcStride, src_center + srcStride + 1, src_center + srcStride + 2,
            src_center + 2*srcStride - 1, src_center + 2*srcStride, src_center + 2*srcStride + 1, src_center + 2*srcStride + 2
        };
        int sum = src[neighbors[0]] - 12 * src[neighbors[1]] - 6 * src[neighbors[2]] + src[neighbors[3]]
                - 12 * src[neighbors[4]] + 144 * src[neighbors[5]] + 72 * src[neighbors[6]] - 12 * src[neighbors[7]]
                - 6 * src[neighbors[8]] + 72 * src[neighbors[9]] + 36 * src[neighbors[10]] - 6 * src[neighbors[11]]
                + src[neighbors[12]] - 12 * src[neighbors[13]] - 6 * src[neighbors[14]] + src[neighbors[15]];
        dst[j * dstStride + i] = (((dst[j * dstStride + i]) + cm[(sum + 128) >> 8] + 1) >> 1);
    }
}
}
