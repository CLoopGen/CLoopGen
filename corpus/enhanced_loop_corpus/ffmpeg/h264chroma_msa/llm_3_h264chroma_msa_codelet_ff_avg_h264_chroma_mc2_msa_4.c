#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *src_offsets[2];
    uint8_t *dst_offsets[2];
    for (cnt = height; cnt--;) {
        src_offsets[0] = &src[0];
        src_offsets[1] = &src[1];
        dst_offsets[0] = &dst[0];
        dst_offsets[1] = &dst[1];

        dst_offsets[0][0] = (dst_offsets[0][0] + src_offsets[0][0] + 1) >> 1;
        dst_offsets[1][0] = (dst_offsets[1][0] + src_offsets[1][0] + 1) >> 1;

        src += stride;
        dst += stride;
    }
}
