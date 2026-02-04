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
    uint8_t *src_base = src;
    uint8_t *dst_base = dst;
    for (cnt = 0; cnt < 2; ++cnt) {
        int32_t offset = cnt * 8;
        {
            dst_base[offset + 0] = src_base[offset + 0];
        }
        ;
        {
            dst_base[offset + 1] = src_base[offset + 1];
        }
        ;
        {
            dst_base[offset + 2] = src_base[offset + 2];
        }
        ;
        {
            dst_base[offset + 3] = src_base[offset + 3];
        }
        ;
        {
            dst_base[offset + 4] = src_base[offset + 4];
        }
        ;
        {
            dst_base[offset + 5] = src_base[offset + 5];
        }
        ;
        {
            dst_base[offset + 6] = src_base[offset + 6];
        }
        ;
        {
            dst_base[offset + 7] = src_base[offset + 7];
        }
        ;
        {
            dst_base[offset + 8] = src_base[offset + 8];
        }
        ;
        {
            dst_base[offset + 9] = src_base[offset + 9];
        }
        ;
        {
            dst_base[offset + 10] = src_base[offset + 10];
        }
        ;
        {
            dst_base[offset + 11] = src_base[offset + 11];
        }
        ;
        {
            dst_base[offset + 12] = src_base[offset + 12];
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
