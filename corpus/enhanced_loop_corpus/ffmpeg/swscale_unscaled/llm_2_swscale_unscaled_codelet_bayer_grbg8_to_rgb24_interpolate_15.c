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
for (i = 2; i < width - 2; i += 2) {
    int src_offset = i * 1;
    int dst_offset = i * 3;

    dst[dst_offset + 0] = ((unsigned int)(src[src_offset - src_stride]) + (unsigned int)(src[src_offset + src_stride])) >> 1;
    dst[dst_offset + 1] = src[src_offset] >> 0;
    dst[dst_offset + 2] = ((unsigned int)(src[src_offset - 1]) + (unsigned int)(src[src_offset + 1])) >> 1;

    dst[dst_offset + 3] = ((unsigned int)(src[src_offset - src_stride]) + (unsigned int)(src[src_offset - src_stride + 2]) + 
                          (unsigned int)(src[src_offset + src_stride]) + (unsigned int)(src[src_offset + src_stride + 2])) >> 2;
    dst[dst_offset + 4] = ((unsigned int)(src[src_offset - src_stride + 1]) + (unsigned int)(src[src_offset]) + 
                          (unsigned int)(src[src_offset + 2]) + (unsigned int)(src[src_offset + src_stride + 1])) >> 2;
    dst[dst_offset + 5] = src[src_offset + 1] >> 0;

    dst += 6;
    src += 2;
}
}
