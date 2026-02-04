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
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        int32_t row_offset_src = loop_cnt * 8 * src_stride;
        int32_t row_offset_dst = loop_cnt * 8 * dst_stride;
        uint8_t *src_block = src + row_offset_src;
        uint8_t *dst_block = dst + row_offset_dst;

        // Interleaved access: write 8x8 block with strided writes but consecutive reads
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                dst_block[i * dst_stride + j] = src_block[i * src_stride + j];
            }
        }

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                dst_block[i * dst_stride + j + 8] = src_block[i * src_stride + j + 8];
            }
        }
    }
    src += 16;
    dst += 16;
}
}
