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
extern  uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 4); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    int offset;
    for (offset = 0; offset < height; offset += 4) {
        int row;
        for (row = 0; row < 4; ++row) {
            uint8_t *s = src_tmp + row * src_stride;
            uint8_t *d = dst_tmp + row * dst_stride;
            int col;
            for (col = 0; col < 16; col += 4) {
                d[col + 0] = s[col + 0];
                d[col + 1] = s[col + 1];
                d[col + 2] = s[col + 2];
                d[col + 3] = s[col + 3];
            }
        }
        src_tmp += (4 * src_stride);
        dst_tmp += (4 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
