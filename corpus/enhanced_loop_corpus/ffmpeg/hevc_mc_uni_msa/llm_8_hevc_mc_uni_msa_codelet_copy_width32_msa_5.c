#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 1); cnt--;) {
    int32_t offset_src = cnt * src_stride;
    int32_t offset_dst = cnt * dst_stride;
    dst[offset_dst] = src[offset_src];
    dst[offset_dst + dst_stride] = src[offset_src + src_stride];
}
}
