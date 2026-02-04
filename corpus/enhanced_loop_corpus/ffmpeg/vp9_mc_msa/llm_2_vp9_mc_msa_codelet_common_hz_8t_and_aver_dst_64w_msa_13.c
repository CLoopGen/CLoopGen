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
    for (cnt = 0; cnt < 2; ++cnt) {
        {
            dst[cnt * 2 + 0] = src[cnt * 2 + 0];
            dst[cnt * 2 + 1] = src[cnt * 2 + 1];
        }
        ;
        {
            dst[cnt * 2 + 4] = src[cnt * 2 + 4];
            dst[cnt * 2 + 5] = src[cnt * 2 + 5];
        }
        ;
        {
            dst[cnt * 2 + 8] = src[cnt * 2 + 8];
            dst[cnt * 2 + 9] = src[cnt * 2 + 9];
        }
        ;
        {
            dst[cnt * 2 + 12] = src[cnt * 2 + 12];
            dst[cnt * 2 + 13] = src[cnt * 2 + 13];
        }
        ;
        {
            dst[cnt * 2 + 16] = src[cnt * 2 + 16];
            dst[cnt * 2 + 17] = src[cnt * 2 + 17];
        }
        ;
        {
            dst[cnt * 2 + 20] = src[cnt * 2 + 20];
            dst[cnt * 2 + 21] = src[cnt * 2 + 21];
        }
        ;
        {
            dst[cnt * 2 + 24] = src[cnt * 2 + 24];
            dst[cnt * 2 + 25] = src[cnt * 2 + 25];
        }
        ;
        {
            dst[cnt * 2 + 28] = src[cnt * 2 + 28];
            dst[cnt * 2 + 29] = src[cnt * 2 + 29];
        }
        ;
        {
            dst[cnt * 2 + 32] = src[cnt * 2 + 32];
            dst[cnt * 2 + 33] = src[cnt * 2 + 33];
        }
        ;
        {
            dst[cnt * 2 + 36] = src[cnt * 2 + 36];
            dst[cnt * 2 + 37] = src[cnt * 2 + 37];
        }
        ;
        {
            dst[cnt * 2 + 40] = src[cnt * 2 + 40];
            dst[cnt * 2 + 41] = src[cnt * 2 + 41];
        }
        ;
        {
            dst[cnt * 2 + 44] = src[cnt * 2 + 44];
            dst[cnt * 2 + 45] = src[cnt * 2 + 45];
        }
        ;
        {
            dst[cnt * 2 + 48] = src[cnt * 2 + 48];
            dst[cnt * 2 + 49] = src[cnt * 2 + 49];
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
