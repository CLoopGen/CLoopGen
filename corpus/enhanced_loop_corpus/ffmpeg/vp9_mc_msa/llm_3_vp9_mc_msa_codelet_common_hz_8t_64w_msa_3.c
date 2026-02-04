#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height; loop_cnt--;) {
    int offset;
    for (offset = 0; offset < src_stride && offset < dst_stride; offset += 4) {
        uint32_t val = *(uint32_t*)&src[offset];
        *(uint32_t*)&dst[offset] = __builtin_bswap32(val);
    }
    src += src_stride;
    dst += dst_stride;
}
}
