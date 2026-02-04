#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 4); cnt--;) {
    int offset_src = 0;
    int offset_dst = 0;
    for (int block = 0; block < 2; ++block) {
        {
            {
                uint8_t temp[8];
                for (int j = 0; j < 8; ++j) {
                    temp[j] = src[offset_src + j * src_stride];
                }
                for (int j = 0; j < 8; ++j) {
                    dst[offset_dst + j * dst_stride] = temp[(j + 1) & 7];
                }
            }
            ;
            {
                uint8_t temp[8];
                for (int j = 0; j < 8; ++j) {
                    temp[j] = src[offset_src + 8 + j * src_stride];
                }
                for (int j = 0; j < 8; ++j) {
                    dst[offset_dst + 8 + j * dst_stride] = temp[(j + 2) & 7];
                }
            }
            ;
        }
        offset_src += 16;
        offset_dst += 16;
    }
    src += (16 * src_stride);
    dst += (16 * dst_stride);
}
}
