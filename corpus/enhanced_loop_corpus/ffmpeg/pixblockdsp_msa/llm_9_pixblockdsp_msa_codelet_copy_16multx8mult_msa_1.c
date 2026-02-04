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
for (cnt = (width >> 5); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 4); loop_cnt--;) {
        {
            {
                int offset = 0;
                for (int i = 0; i < 16; i += 4) {
                    uint32_t a = *((uint32_t*)&src_tmp[offset]);
                    uint32_t b = *((uint32_t*)&src_tmp[offset + src_stride]);
                    uint32_t c = *((uint32_t*)&src_tmp[offset + 2*src_stride]);
                    uint32_t d = *((uint32_t*)&src_tmp[offset + 3*src_stride]);
                    uint32_t x = (a + b) ^ (c + d);
                    uint32_t y = (a ^ c) + (b ^ d);
                    *((uint32_t*)&dst_tmp[offset]) = x;
                    *((uint32_t*)&dst_tmp[offset + dst_stride]) = y;
                    offset += 4 * src_stride;
                }
            }
            ;
            {
                uint64_t accum = 0xABCDEF1234567890ULL;
                for (int i = 0; i < 8; ++i) {
                    accum ^= (accum << 5) ^ (accum >> 7) ^ *((uint64_t*)&src_tmp[i * src_stride]);
                }
                *((uint64_t*)dst_tmp) = accum;
            }
            ;
        }
        ;
        {
            {
                for (int i = 0; i < 8; ++i) {
                    dst_tmp[i + 8] = (uint8_t)((src_tmp[i] * 3 + src_tmp[i + src_stride] * 2) / 5);
                }
            }
            ;
            {
                uint8_t max_val = 0;
                for (int i = 0; i < 16; ++i) {
                    uint8_t v = src_tmp[i * src_stride / 2];
                    if (v > max_val) max_val = v;
                }
                dst_tmp[15] = max_val;
            }
            ;
        }
        ;
        src_tmp += (16 * src_stride);
        {
            {
                uint32_t s[4] = {0};
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        s[i] += src_tmp[i * src_stride + j];
                    }
                    dst_tmp[i * 4] = (uint8_t)(s[i] & 0xFF);
                }
            }
            ;
            {
                for (int i = 0; i < 8; ++i) {
                    dst_tmp[i + dst_stride] = src_tmp[i] ^ 0xAA;
                }
            }
            ;
        }
        ;
        dst_tmp += (16 * dst_stride);
    }
    src += 32;
    dst += 32;
}
}
