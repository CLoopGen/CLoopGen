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
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;
extern int32_t loop_cnt;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = width >> 4; cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    uint8_t temp1 = src_tmp[0];
    uint8_t temp2 = src_tmp[src_stride * 3];
    uint8_t temp3 = src_tmp[src_stride * 6];
    uint8_t temp4 = src_tmp[src_stride * 7];
    int16_t accumulator = 0;
    accumulator += temp1 + temp2 + temp3 + temp4;
    dst_tmp[0] = accumulator;
    dst_tmp[dst_stride] = accumulator + 1;
    dst_tmp[2*dst_stride] = accumulator + 2;
    dst_tmp[3*dst_stride] = accumulator + 3;
    src_tmp += (7 * src_stride);
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint8_t val_top = src_tmp[-src_stride];
        uint8_t val_mid = src_tmp[0];
        uint8_t val_low = src_tmp[src_stride];
        int16_t avg = (val_top + val_mid + val_low) / 3;
        dst_tmp[0] = avg;
        dst_tmp[dst_stride] = avg + 10;
        dst_tmp[2*dst_stride] = avg + 20;
        dst_tmp[3*dst_stride] = avg + 30;
        src_tmp += (4 * src_stride);
        dst_tmp += (4 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
