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
for (i = 2; i < width - 2; i += 4) {
    // Unrolled by factor of 2 to increase computational intensity
    int offset1 = 0, offset2 = 2;
    
    // First output pixel (i)
    dst[offset1 * dst_stride + 0 * 3 + 2] = ((unsigned int)(src[(-1) * src_stride + -1]) + (unsigned int)(src[(-1) * src_stride + 1]) + (unsigned int)(src[(1) * src_stride + -1]) + (unsigned int)(src[(1) * src_stride + 1])) >> 2;
    dst[offset1 * dst_stride + 0 * 3 + 1] = ((unsigned int)(src[(-1) * src_stride + 0]) + (unsigned int)(src[0 * src_stride + -1]) + (unsigned int)(src[0 * src_stride + 1]) + (unsigned int)(src[(1) * src_stride + 0])) >> 2;
    dst[offset1 * dst_stride + 0 * 3 + 0] = src[0 * src_stride + 0];
    dst[offset1 * dst_stride + 1 * 3 + 2] = ((unsigned int)(src[(-1) * src_stride + 1]) + (unsigned int)(src[(1) * src_stride + 1])) >> 1;
    dst[offset1 * dst_stride + 1 * 3 + 1] = src[0 * src_stride + 1];
    dst[offset1 * dst_stride + 1 * 3 + 0] = ((unsigned int)(src[0 * src_stride + 0]) + (unsigned int)(src[0 * src_stride + 2])) >> 1;
    dst[offset1 * dst_stride + 2 * 3 + 2] = ((unsigned int)(src[(1) * src_stride + -1]) + (unsigned int)(src[(1) * src_stride + 1])) >> 1;
    dst[offset1 * dst_stride + 2 * 3 + 1] = src[(1) * src_stride + 0];
    dst[offset1 * dst_stride + 2 * 3 + 0] = ((unsigned int)(src[0 * src_stride + 0]) + (unsigned int)(src[2 * src_stride + 0])) >> 1;
    dst[offset1 * dst_stride + 3 * 3 + 2] = src[(1) * src_stride + 1];
    dst[offset1 * dst_stride + 3 * 3 + 1] = ((unsigned int)(src[0 * src_stride + 1]) + (unsigned int)(src[(1) * src_stride + 0]) + (unsigned int)(src[(1) * src_stride + 2]) + (unsigned int)(src[(2) * src_stride + 1])) >> 2;
    dst[offset1 * dst_stride + 3 * 3 + 0] = ((unsigned int)(src[0 * src_stride + 0]) + (unsigned int)(src[0 * src_stride + 2]) + (unsigned int)(src[(2) * src_stride + 0]) + (unsigned int)(src[(2) * src_stride + 2])) >> 2;

    // Second output pixel (i+2), shifted by 2 in x
    dst[offset2 * dst_stride + 0 * 3 + 2] = ((unsigned int)(src[(-1) * src_stride + 1]) + (unsigned int)(src[(-1) * src_stride + 3]) + (unsigned int)(src[(1) * src_stride + 1]) + (unsigned int)(src[(1) * src_stride + 3])) >> 2;
    dst[offset2 * dst_stride + 0 * 3 + 1] = ((unsigned int)(src[(-1) * src_stride + 2]) + (unsigned int)(src[0 * src_stride + 1]) + (unsigned int)(src[0 * src_stride + 3]) + (unsigned int)(src[(1) * src_stride + 2])) >> 2;
    dst[offset2 * dst_stride + 0 * 3 + 0] = src[0 * src_stride + 2];
    dst[offset2 * dst_stride + 1 * 3 + 2] = ((unsigned int)(src[(-1) * src_stride + 3]) + (unsigned int)(src[(1) * src_stride + 3])) >> 1;
    dst[offset2 * dst_stride + 1 * 3 + 1] = src[0 * src_stride + 3];
    dst[offset2 * dst_stride + 1 * 3 + 0] = ((unsigned int)(src[0 * src_stride + 2]) + (unsigned int)(src[0 * src_stride + 4])) >> 1;
    dst[offset2 * dst_stride + 2 * 3 + 2] = ((unsigned int)(src[(1) * src_stride + 1]) + (unsigned int)(src[(1) * src_stride + 3])) >> 1;
    dst[offset2 * dst_stride + 2 * 3 + 1] = src[(1) * src_stride + 2];
    dst[offset2 * dst_stride + 2 * 3 + 0] = ((unsigned int)(src[0 * src_stride + 2]) + (unsigned int)(src[2 * src_stride + 2])) >> 1;
    dst[offset2 * dst_stride + 3 * 3 + 2] = src[(1) * src_stride + 3];
    dst[offset2 * dst_stride + 3 * 3 + 1] = ((unsigned int)(src[0 * src_stride + 3]) + (unsigned int)(src[(1) * src_stride + 2]) + (unsigned int)(src[(1) * src_stride + 4]) + (unsigned int)(src[(2) * src_stride + 3])) >> 2;
    dst[offset2 * dst_stride + 3 * 3 + 0] = ((unsigned int)(src[0 * src_stride + 2]) + (unsigned int)(src[0 * src_stride + 4]) + (unsigned int)(src[(2) * src_stride + 2]) + (unsigned int)(src[(2) * src_stride + 4])) >> 2;

    src += 4 * 1;
    dst += 12;
}
}
