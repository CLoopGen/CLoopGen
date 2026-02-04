#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 1); cnt--;) {
    uint32_t sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += src[i * src_stride];
    }
    dst[0] = (uint8_t)(sum >> 8);
    src += (2 * src_stride);
    dst += (2 * dst_stride);
}
}
