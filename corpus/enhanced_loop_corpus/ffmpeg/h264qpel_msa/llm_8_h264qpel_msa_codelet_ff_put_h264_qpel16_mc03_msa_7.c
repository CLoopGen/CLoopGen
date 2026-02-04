#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 8; loop_cnt--;) {
    uint32_t acc1 = 0, acc2 = 0, acc3 = 0, acc4 = 0;
    for (int i = 0; i < 4; ++i) {
        acc1 += src[i + 0*stride];
        acc2 += src[i + 1*stride];
        acc3 += src[i + 2*stride];
        acc4 += src[i + 3*stride];
    }
    dst[0*stride] = acc1 & 0xFF;
    dst[1*stride] = acc2 & 0xFF;
    dst[2*stride] = acc3 & 0xFF;
    dst[3*stride] = acc4 & 0xFF;
    src += (4 * stride);
    dst += (4 * stride);
}
}
