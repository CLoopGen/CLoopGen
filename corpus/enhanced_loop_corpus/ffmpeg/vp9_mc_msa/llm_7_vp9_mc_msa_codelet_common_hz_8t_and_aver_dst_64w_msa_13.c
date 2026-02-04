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
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height; loop_cnt--;) {
    uint8_t local_buffer[64];
    for (cnt = 0; cnt < 2; ++cnt) {
        uint32_t idx_src = cnt * 8;
        uint32_t idx_dst = cnt * 8;
        local_buffer[idx_dst + 0] = src[idx_src + 0] + 10;
        local_buffer[idx_dst + 1] = src[idx_src + 1] + local_buffer[idx_dst + 0];
        local_buffer[idx_dst + 2] = src[idx_src + 2] + local_buffer[idx_dst + 1];
        local_buffer[idx_dst + 3] = src[idx_src + 3] ^ local_buffer[idx_dst + 2];
        local_buffer[idx_dst + 4] = local_buffer[idx_dst + 3] + 5;
        local_buffer[idx_dst + 5] = src[idx_src + 5] | local_buffer[idx_dst + 4];
        local_buffer[idx_dst + 6] = local_buffer[idx_dst + 5] + local_buffer[idx_dst + 0];
        local_buffer[idx_dst + 7] = src[idx_src + 7] + local_buffer[idx_dst + 6];

        {
            dst[idx_dst + 0] = local_buffer[idx_dst + 0];
        }
        ;
        {
            dst[idx_dst + 1] = local_buffer[idx_dst + 1];
        }
        ;
        {
            dst[idx_dst + 2] = local_buffer[idx_dst + 2];
        }
        ;
        {
            dst[idx_dst + 3] = local_buffer[idx_dst + 3];
        }
        ;
        {
            dst[idx_dst + 4] = local_buffer[idx_dst + 4];
        }
        ;
        {
            dst[idx_dst + 5] = local_buffer[idx_dst + 5];
        }
        ;
        {
            dst[idx_dst + 6] = local_buffer[idx_dst + 6];
        }
        ;
        {
            dst[idx_dst + 7] = local_buffer[idx_dst + 7];
        }
        ;
        {
            local_buffer[idx_dst + 0] ^= 0xAA;
        }
        ;
        {
            local_buffer[idx_dst + 4] ^= 0x55;
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
    }
    src += src_stride;
    dst += dst_stride;
}
}
