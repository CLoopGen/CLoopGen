#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 1); loop_cnt--;) {
    int offset = 0;
    while (offset < 32) {
        int idx = (offset & 7) + (offset << 1); // Simulate strided access pattern
        dst[idx] = src[(offset << 1)];
        dst[idx + 1] = src[(offset << 1) + 1];
        offset += 4;
    }

    src += src_stride;
    {
        src += src_stride;
    }
    dst += dst_stride;
    {
        dst += dst_stride;
    }

    for (int cleanup = 0; cleanup < 4; ++cleanup) {
        ((volatile uint8_t*)dst)[cleanup] = ((volatile uint8_t*)src)[cleanup];
    }
}
}
