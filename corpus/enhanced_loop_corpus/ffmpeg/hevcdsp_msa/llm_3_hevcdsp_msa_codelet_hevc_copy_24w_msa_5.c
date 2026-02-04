#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        // Variant 2: Strided memory access with reversed iteration and stride scaling
        int32_t scaled_src_stride = src_stride * 2;
        int32_t scaled_dst_stride = dst_stride * 2;

        for (int offset = 3; offset >= 0; --offset) {
            uint8_t *s = src + offset * src_stride;
            int16_t *d = dst + offset * dst_stride;

            // Simulate processing with strided access pattern across larger steps
            d[0] = s[0];
            d[scaled_dst_stride] = s[scaled_src_stride];
            d[2 * scaled_dst_stride] = s[2 * scaled_src_stride];
            d[3 * scaled_dst_stride] = s[3 * scaled_src_stride];
        }

        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
