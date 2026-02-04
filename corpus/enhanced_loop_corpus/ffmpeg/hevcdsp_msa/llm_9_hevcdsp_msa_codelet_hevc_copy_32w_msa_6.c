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
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        // Unroll by 8 rows instead of 4, doubling computational load per iteration
        uint8_t* local_src = src;
        int16_t* local_dst = dst;

        // Process 8 rows with increased arithmetic intensity: scale and offset with multiplication
        for (int row = 0; row < 8; row += 2) {
            local_dst[0] = (int16_t)((local_src[0] << 3) - local_src[0] + 5); // 7*x + 5
            local_dst[1] = (int16_t)((local_src[1] << 2) + local_src[1] - 3); // 5*x - 3

            local_src += src_stride;
            local_dst += dst_stride;

            local_dst[0] = (int16_t)((local_src[0] * 9) >> 1); // ~4.5*x
            local_dst[1] = (int16_t)((local_src[1] * 3) + 10);

            local_src += src_stride;
            local_dst += dst_stride;
        }

        src += (8 * src_stride);
        dst += (8 * dst_stride);
    }
}
