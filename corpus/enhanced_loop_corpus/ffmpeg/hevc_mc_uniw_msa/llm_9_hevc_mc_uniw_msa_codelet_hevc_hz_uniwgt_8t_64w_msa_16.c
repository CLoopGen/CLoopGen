#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height >> 1; loop_cnt > 0; loop_cnt--) {
    src_tmp = src;
    dst_tmp = dst;
    for (cnt = 1; cnt > 0; cnt--) {
        uint32_t i;
        for (i = 0; i < 64; i += 4) {
            uint8_t val0 = src_tmp[i + 0];
            uint8_t val1 = src_tmp[i + 1];
            uint8_t val2 = src_tmp[i + 2];
            uint8_t val3 = src_tmp[i + 3];

            dst_tmp[i + 0] = (val0 << 1) ^ val1;
            dst_tmp[i + 1] = (val1 << 1) ^ val2;
            dst_tmp[i + 2] = (val2 << 1) ^ val3;
            dst_tmp[i + 3] = (val3 << 1) ^ val0;

            dst_tmp[i + 4] = val0 ^ val2;
            dst_tmp[i + 5] = val1 ^ val3;
            dst_tmp[i + 6] = (val0 + val1 + val2 + val3) / 4;
            dst_tmp[i + 7] = (val0 > val3) ? val0 : val3;
        }

        src_tmp += 64;
        for (i = 0; i < 64; i += 8) {
            dst_tmp[64 + i + 0] = src_tmp[i + 0] + 10;
            dst_tmp[64 + i + 1] = src_tmp[i + 1] + 20;
            dst_tmp[64 + i + 2] = src_tmp[i + 2] + 30;
            dst_tmp[64 + i + 3] = src_tmp[i + 3] + 40;
            dst_tmp[64 + i + 4] = src_tmp[i + 4] + 50;
            dst_tmp[64 + i + 5] = src_tmp[i + 5] + 60;
            dst_tmp[64 + i + 6] = src_tmp[i + 6] + 70;
            dst_tmp[64 + i + 7] = src_tmp[i + 7] + 80;
        }

        dst_tmp += 128;
    }

    src += src_stride * 2;
    dst += dst_stride * 2;

    if (--loop_cnt <= 0) break;

    src_tmp = src;
    dst_tmp = dst;
    for (cnt = 1; cnt > 0; cnt--) {
        for (uint32_t i = 0; i < 32; ++i) {
            uint8_t a = src_tmp[i];
            uint8_t b = src_tmp[i + 32];
            dst_tmp[i]       = (a & 0xF0) | (b & 0x0F);
            dst_tmp[i + 32]  = (b & 0xF0) | (a & 0x0F);
            dst_tmp[i + 64]  = a ^ b;
            dst_tmp[i + 96]  = (a + b) >> 1;
        }
        dst_tmp += 128;
    }

    src += src_stride;
    dst += dst_stride;
}
}
