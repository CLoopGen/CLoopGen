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
for (i = 0; i < width; i += 2) {
    int dst_offset_00 = (0) * dst_stride + (0) * 3;
    int dst_offset_01 = (0) * dst_stride + (1) * 3;
    int dst_offset_10 = (1) * dst_stride + (0) * 3;
    int dst_offset_11 = (1) * dst_stride + (1) * 3;
    int src_offset_00 = (0) * src_stride;
    int src_offset_10 = (1) * src_stride;

    dst[dst_offset_00 + 0] = dst[dst_offset_01 + 0] = dst[dst_offset_11 + 0] = dst[dst_offset_10 + 0] = src[src_offset_10 + 1];
    dst[dst_offset_00 + 1] = src[src_offset_00 + 0];
    dst[dst_offset_11 + 1] = src[src_offset_10 + 1];
    dst[dst_offset_01 + 1] = dst[dst_offset_10 + 1] = ((unsigned int)src[src_offset_00 + 0] + (unsigned int)src[src_offset_10 + 1]) >> 1;
    dst[dst_offset_11 + 2] = dst[dst_offset_00 + 2] = dst[dst_offset_01 + 2] = dst[dst_offset_10 + 2] = src[src_offset_00 + 1];

    src += 2;
    dst += 6;
}
}
