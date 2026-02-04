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
    uint8_t acc_buffer[16];
    for (v_cnt = 0; v_cnt < width; v_cnt += 16) {
        acc_buffer[0]  = src_orig[1]  + src_orig[0];
        acc_buffer[1]  = src_orig[3]  + src_orig[2];
        acc_buffer[2]  = src_orig[5]  + src_orig[4];
        acc_buffer[3]  = src_orig[7]  + src_orig[6];
        acc_buffer[4]  = src_orig[9]  + src_orig[8];
        acc_buffer[5]  = src_orig[11] + src_orig[10];
        acc_buffer[6]  = src_orig[13] + src_orig[12];
        acc_buffer[7]  = src_orig[15] + src_orig[14];

        acc_buffer[8]  = acc_buffer[0] + acc_buffer[1];
        acc_buffer[9]  = acc_buffer[2] + acc_buffer[3];
        acc_buffer[10] = acc_buffer[4] + acc_buffer[5];
        acc_buffer[11] = acc_buffer[6] + acc_buffer[7];

        acc_buffer[12] = acc_buffer[8] + acc_buffer[9];
        acc_buffer[13] = acc_buffer[10] + acc_buffer[11];

        dst_orig[0] = acc_buffer[12];
        dst_orig[1] = acc_buffer[13];

        for (int i = 2; i < 16; ++i) {
            dst_orig[i] = acc_buffer[(i * 7) % 14]; 
        }

        src_orig += 16;
        dst_orig += 16;
    }
    src += (src_stride << 2);
    dst += (dst_stride << 2);
}
}
