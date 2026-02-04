#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 3); loop_cnt--;) {
    uint8_t *s = src;
    uint8_t *d = dst;
    for (int row = 0; row < 8; row += 2) {
        d[0] = (uint8_t)((s[0] + s[src_stride]) >> 1);
        d[1] = (uint8_t)((s[1] + s[src_stride + 1]) >> 1);
        d[2] = (uint8_t)((s[2] + s[src_stride + 2]) >> 1);
        d[3] = (uint8_t)((s[3] + s[src_stride + 3]) >> 1);
        d[4] = (uint8_t)((s[4] + s[src_stride + 4]) >> 1);
        d[5] = (uint8_t)((s[5] + s[src_stride + 5]) >> 1);
        d[6] = (uint8_t)((s[6] + s[src_stride + 6]) >> 1);
        d[7] = (uint8_t)((s[7] + s[src_stride + 7]) >> 1);

        s += (2 * src_stride);
        d += (2 * dst_stride);
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
