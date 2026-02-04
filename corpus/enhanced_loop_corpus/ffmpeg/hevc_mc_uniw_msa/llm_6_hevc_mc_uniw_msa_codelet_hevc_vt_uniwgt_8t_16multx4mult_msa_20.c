#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t weightmul16;
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern int32_t loop_cnt;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = weightmul16; cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    uint8_t temp_accum = 0;
    for (int i = 0; i < 7; i++) {
        temp_accum += src_tmp[i * src_stride];
    }
    dst_tmp[0] = temp_accum;
    src_tmp += (7 * src_stride);
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint8_t val1 = src_tmp[0 * src_stride];
        uint8_t val2 = src_tmp[1 * src_stride];
        uint8_t val3 = src_tmp[2 * src_stride];
        uint8_t val4 = src_tmp[3 * src_stride];
        
        dst_tmp[0 * dst_stride] = val1 + temp_accum;
        dst_tmp[1 * dst_stride] = val2 + temp_accum;
        dst_tmp[2 * dst_stride] = val3 + temp_accum;
        dst_tmp[3 * dst_stride] = val4 + temp_accum;

        temp_accum = (val1 + val2 + val3 + val4) >> 2;

        src_tmp += (4 * src_stride);
        dst_tmp += (4 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
