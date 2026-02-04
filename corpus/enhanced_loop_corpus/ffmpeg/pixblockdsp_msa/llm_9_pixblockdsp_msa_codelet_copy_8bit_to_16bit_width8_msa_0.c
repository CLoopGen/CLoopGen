#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t *dst_ptr;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 1); cnt--;) {
    {
        src += src_stride;
        dst_ptr += dst_stride;
    }
    {
        src += src_stride;
        dst_ptr += dst_stride;
    }
    {
        src += 2 * src_stride;
        dst_ptr += 2 * dst_stride;
    }
    dst_ptr += 2 * dst_stride;
    cnt--; 
    if (cnt <= 0) break;
}
}
