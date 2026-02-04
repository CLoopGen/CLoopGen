#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern int32_t cnt;
extern int32_t loop_cnt;
extern  uint8_t *src_tmp;
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 4); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 4); loop_cnt--;) {
        for (int blk = 0; blk < 2; ++blk) {
            {
                uint8_t a = src_tmp[0], b = src_tmp[1];
                uint8_t c = src_tmp[src_stride], d = src_tmp[src_stride + 1];
                uint32_t det = (uint32_t)(a * d - b * c + 256) & 0xFF;
                dst_tmp[0] = (uint8_t)det;
            }
            ;
            {
                uint16_t x = (src_tmp[2] << 4) | (src_tmp[3] & 0xF);
                uint8_t y = (uint8_t)((x >> 6) ^ (x & 0x3F));
                dst_tmp[1] = y;
            }
            ;
            src_tmp += 2;
            dst_tmp += 2;
        }
        src_tmp += (2 * src_stride - 4);
        dst_tmp += (2 * dst_stride - 4);
        for (int blk = 0; blk < 4; ++blk) {
            dst_tmp[blk] ^= src_tmp[blk] ^ (uint8_t)(blk * 7);
        }
        src_tmp += 4;
        dst_tmp += 4;
    }
    src += 16;
    dst += 16;
}
}
