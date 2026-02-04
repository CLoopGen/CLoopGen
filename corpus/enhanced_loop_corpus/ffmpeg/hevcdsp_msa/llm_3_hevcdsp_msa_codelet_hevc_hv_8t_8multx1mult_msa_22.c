#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern uint32_t loop_cnt;
extern uint32_t cnt;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = width >> 3; cnt--;) {
    for (loop_cnt = 0; loop_cnt < height; loop_cnt++) {
        uint8_t *row_base = &src[loop_cnt * src_stride];
        int16_t *dst_row = &dst[loop_cnt * dst_stride];

        for (int k = 0; k < 8; k++) {
            dst_row[k] = (int16_t)row_base[k * src_stride];
        }
    }
    src += 8;
    dst += 8;
}
}
