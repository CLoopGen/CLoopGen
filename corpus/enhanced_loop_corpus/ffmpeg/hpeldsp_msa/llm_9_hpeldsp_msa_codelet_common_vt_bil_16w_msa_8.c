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
    {
        {
            uint8_t offset = 0;
            while (offset < 8) {  // Simulated unroll with arithmetic intensity
                uint8_t temp[4];
                temp[0] = src[offset * src_stride + 0];
                temp[1] = src[offset * src_stride + 1];
                temp[2] = src[offset * src_stride + 2];
                temp[3] = src[offset * src_stride + 3];
                dst[offset * dst_stride + 0] = temp[0] ^ 0xFF;
                dst[offset * dst_stride + 1] = temp[1] ^ 0xFF;
                dst[offset * dst_stride + 2] = temp[2] ^ 0xFF;
                dst[offset * dst_stride + 3] = temp[3] ^ 0xFF;
                offset++;
            }
        }
        ;
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
