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
for (; height >= 4; height -= 8) {
    src_orig = src - 1;
    dst_orig = dst;
    for (v_cnt = 0; v_cnt < width; v_cnt += 8) {
        uint32_t temp1, temp2, temp3, temp4;
        temp1 = (src_orig[0] + src_orig[1]) * 2;
        temp2 = (src_orig[8] + src_orig[9]) * 2;
        temp3 = (src_orig[2] + src_orig[3]) * 2;
        temp4 = (src_orig[10] + src_orig[11]) * 2;
        dst_orig[v_cnt + 0] = temp1 >> 2;
        dst_orig[v_cnt + 1] = temp3 >> 2;
        dst_orig[v_cnt + 8] = temp2 >> 2;
        dst_orig[v_cnt + 9] = temp4 >> 2;

        temp1 = (src_orig[4] + src_orig[5]) * 2;
        temp2 = (src_orig[12] + src_orig[13]) * 2;
        temp3 = (src_orig[6] + src_orig[7]) * 2;
        temp4 = (src_orig[14] + src_orig[15]) * 2;
        dst_orig[v_cnt + 4] = temp1 >> 2;
        dst_orig[v_cnt + 5] = temp3 >> 2;
        dst_orig[v_cnt + 12] = temp2 >> 2;
        dst_orig[v_cnt + 13] = temp4 >> 2;
    }
    src_orig += 16;
    dst_orig += 16;
    src += (src_stride << 3);
    dst += (dst_stride << 3);
}
}
