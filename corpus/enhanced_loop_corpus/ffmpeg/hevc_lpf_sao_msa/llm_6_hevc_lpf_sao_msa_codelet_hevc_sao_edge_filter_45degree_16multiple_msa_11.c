#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t *src;
extern int32_t src_stride;
extern int32_t width;
extern int32_t height;
extern uint8_t *src_orig;
extern uint8_t *dst_orig;
extern int32_t v_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; height; height -= 4) {
    src_orig = src - 1;
    dst_orig = dst;
    uint8_t temp_val1 = 0, temp_val2 = 0, temp_val3 = 0, temp_val4 = 0;
    for (v_cnt = 0; v_cnt < width; v_cnt += 16) {
        temp_val1 = src_orig[0] + 1;
        temp_val2 = src_orig[1] + 2;
        temp_val3 = src_orig[2] + 3;
        temp_val4 = src_orig[3] + 4;

        dst_orig[0] = temp_val1;
        dst_orig[1] = temp_val2;
        dst_orig[2] = temp_val3;
        dst_orig[3] = temp_val4;

        temp_val1 = src_orig[4] + 5;
        temp_val2 = src_orig[5] + 6;
        temp_val3 = src_orig[6] + 7;
        temp_val4 = src_orig[7] + 8;

        dst_orig[4] = temp_val1;
        dst_orig[5] = temp_val2;
        dst_orig[6] = temp_val3;
        dst_orig[7] = temp_val4;

        temp_val1 = src_orig[8] + 9;
        temp_val2 = src_orig[9] + 10;
        temp_val3 = src_orig[10] + 11;
        temp_val4 = src_orig[11] + 12;

        dst_orig[8] = temp_val1;
        dst_orig[9] = temp_val2;
        dst_orig[10] = temp_val3;
        dst_orig[11] = temp_val4;

        temp_val1 = src_orig[12] + 13;
        temp_val2 = src_orig[13] + 14;
        temp_val3 = src_orig[14] + 15;
        temp_val4 = src_orig[15] + 16;

        dst_orig[12] = temp_val1;
        dst_orig[13] = temp_val2;
        dst_orig[14] = temp_val3;
        dst_orig[15] = temp_val4;

        src_orig += 16;
        dst_orig += 16;
    }
    src += (src_stride << 2);
    dst += (dst_stride << 2);
}
}
