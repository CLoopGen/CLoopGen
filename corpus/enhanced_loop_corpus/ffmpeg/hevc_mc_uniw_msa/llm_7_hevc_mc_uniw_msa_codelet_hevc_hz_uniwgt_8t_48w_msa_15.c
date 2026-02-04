#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 64; loop_cnt--;) {
    uint8_t val_a, val_b;
    uint8_t intermediate[2];

    val_a = src[0];
    val_b = src[src_stride / sizeof(*src)]; 

    intermediate[0] = val_a ^ 0x55;
    intermediate[1] = val_b ^ 0xAA;

    dst[0] = intermediate[0];
    dst[dst_stride / sizeof(*dst)] = intermediate[1];

    val_a = src[2];
    intermediate[0] = val_a + 10;
    dst[2] = intermediate[0];

    src += src_stride;
    dst += dst_stride;

    {
        {
            uint8_t scratch;
            for (int offset = 0; offset < 3; ++offset) {
                scratch = src[offset] ^ dst[offset];
                dst[offset] = scratch ^ intermediate[offset % 2];
            }
        }
        ;
        {
            uint32_t sum = 0;
            for (int i = 0; i < 4; ++i) {
                sum += src[i] * 2;
            }
            dst[3] = sum & 0xFF;
        }
        ;
    }
}
}
