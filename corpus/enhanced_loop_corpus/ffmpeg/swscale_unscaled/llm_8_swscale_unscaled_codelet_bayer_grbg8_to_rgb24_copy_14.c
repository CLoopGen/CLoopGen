#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i += 4) {
    // Unrolled by factor of 2 to increase computational intensity
    int offset1 = (0) * dst_stride, offset2 = (1) * dst_stride;
    int src_offset1 = (0) * src_stride, src_offset2 = (1) * src_stride;

    // First block (i)
    dst[offset1 + 0*3 + 2] = dst[offset1 + 1*3 + 2] = dst[offset2 + 1*3 + 2] = dst[offset2 + 0*3 + 2] = src[src_offset2 + 0] >> 0;
    dst[offset1 + 0*3 + 1] = src[src_offset1 + 0] >> 0;
    dst[offset2 + 1*3 + 1] = src[src_offset2 + 1] >> 0;
    dst[offset1 + 1*3 + 1] = dst[offset2 + 0*3 + 1] = ((unsigned int)src[src_offset1 + 0] + (unsigned int)src[src_offset2 + 1]) >> 1;
    dst[offset2 + 1*3 + 0] = dst[offset1 + 0*3 + 0] = dst[offset1 + 1*3 + 0] = dst[offset2 + 0*3 + 0] = src[src_offset1 + 1] >> 0;

    // Second block (i+2), shifted by 2 in source and destination
    if (i + 2 < width) {
        dst[offset1 + 0*3 + 2] = dst[offset1 + 1*3 + 2] = dst[offset2 + 1*3 + 2] = dst[offset2 + 0*3 + 2] = src[src_offset2 + 2] >> 0;
        dst[offset1 + 0*3 + 1] = src[src_offset1 + 2] >> 0;
        dst[offset2 + 1*3 + 1] = src[src_offset2 + 3] >> 0;
        dst[offset1 + 1*3 + 1] = dst[offset2 + 0*3 + 1] = ((unsigned int)src[src_offset1 + 2] + (unsigned int)src[src_offset2 + 3]) >> 1;
        dst[offset2 + 1*3 + 0] = dst[offset1 + 0*3 + 0] = dst[offset1 + 1*3 + 0] = dst[offset2 + 0*3 + 0] = src[src_offset1 + 3] >> 0;
    }

    src += 4 * 1;
    dst += 12; // Double the step due to unrolling
}
}
