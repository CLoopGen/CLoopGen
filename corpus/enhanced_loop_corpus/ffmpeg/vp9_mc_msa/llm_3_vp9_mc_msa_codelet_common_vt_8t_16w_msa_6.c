#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    // Strided memory access: process one row at a time but with vertical stride pattern
    for (int offset = 0; offset < 4; ++offset) {
        uint8_t *s = src + offset * src_stride;
        uint8_t *d = dst + offset * dst_stride;

        // Process 4 consecutive bytes per row
        for (int col = 0; col < 4; ++col) {
            d[col] = s[col];
        }
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
