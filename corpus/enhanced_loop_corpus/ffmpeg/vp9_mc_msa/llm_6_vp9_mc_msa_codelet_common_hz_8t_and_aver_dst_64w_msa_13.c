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
    uint32_t temp_accum = 0;
    for (cnt = 0; cnt < 2; ++cnt) {
        temp_accum += src[cnt] * 2;
        dst[cnt] = temp_accum & 0xFF;
        temp_accum += dst[(cnt + 1) % 2] ^ src[cnt];
        {
            dst[cnt + 4] = src[cnt + 4] + (temp_accum >> 4);
        }
        ;
        {
            temp_accum += src[cnt + 8] - dst[cnt + 8];
            dst[cnt + 8] = temp_accum & 0xFF;
        }
        ;
        {
            dst[cnt + 12] = src[cnt + 12];
        }
        ;
        {
            temp_accum ^= src[cnt + 16] + 1;
            dst[cnt + 16] = temp_accum;
        }
        ;
        {
            dst[cnt + 20] = temp_accum + src[cnt + 20];
        }
        ;
        {
            temp_accum += 5;
        }
        ;
        {
            dst[cnt + 24] = temp_accum;
        }
        ;
        {
            temp_accum = (temp_accum << 1) | (temp_accum >> 7);
        }
        ;
        {
            dst[cnt + 28] = src[cnt + 28] ^ temp_accum;
        }
        ;
        {
            temp_accum += src[cnt + 32] + dst[cnt + 32];
        }
        ;
        {
            dst[cnt + 36] = temp_accum & src[cnt + 36];
        }
        ;
        {
            temp_accum -= 3;
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
