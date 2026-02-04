#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 4); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    uint8_t temp_val1 = src_tmp[0];
    uint8_t temp_val2 = src_tmp[src_stride];
    uint8_t temp_val3 = src_tmp[2 * src_stride];
    uint8_t temp_val4 = src_tmp[3 * src_stride];
    {
        dst_tmp[0] = temp_val1;
        dst_tmp[dst_stride] = temp_val2;
        dst_tmp[2 * dst_stride] = temp_val3;
        dst_tmp[3 * dst_stride] = temp_val4;
    }
    ;
    {
        temp_val1 = src_tmp[4 * src_stride];
        temp_val2 = src_tmp[5 * src_stride];
        temp_val3 = src_tmp[6 * src_stride];
    }
    ;
    src_tmp += (7 * src_stride);
    {
        dst_tmp[4 * dst_stride] = temp_val1;
        dst_tmp[5 * dst_stride] = temp_val2;
        dst_tmp[6 * dst_stride] = temp_val3;
    }
    ;
    {
        temp_val4 = src_tmp[0];
    }
    ;
    {
        dst_tmp[7 * dst_stride] = temp_val4;
    }
    ;
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        temp_val1 = src_tmp[0];
        temp_val2 = src_tmp[src_stride];
        temp_val3 = src_tmp[2 * src_stride];
        temp_val4 = src_tmp[3 * src_stride];
        {
            dst_tmp[0] = temp_val1;
            dst_tmp[dst_stride] = temp_val2;
            dst_tmp[2 * dst_stride] = temp_val3;
            dst_tmp[3 * dst_stride] = temp_val4;
        }
        ;
        {
            temp_val1 = src_tmp[4 * src_stride];
            temp_val2 = src_tmp[5 * src_stride];
            temp_val3 = src_tmp[6 * src_stride];
            temp_val4 = src_tmp[7 * src_stride];
        }
        ;
        src_tmp += (4 * src_stride);
        {
            dst_tmp[4 * dst_stride] = temp_val1;
            dst_tmp[5 * dst_stride] = temp_val2;
            dst_tmp[6 * dst_stride] = temp_val3;
            dst_tmp[7 * dst_stride] = temp_val4;
        }
        ;
        {
            temp_val1 = src_tmp[0];
            temp_val2 = src_tmp[src_stride];
            temp_val3 = src_tmp[2 * src_stride];
            temp_val4 = src_tmp[3 * src_stride];
        }
        ;
        {
            dst_tmp[8 * dst_stride] = temp_val1;
            dst_tmp[9 * dst_stride] = temp_val2;
            dst_tmp[10 * dst_stride] = temp_val3;
            dst_tmp[11 * dst_stride] = temp_val4;
        }
        ;
        {
            temp_val1 = src_tmp[4 * src_stride];
            temp_val2 = src_tmp[5 * src_stride];
            temp_val3 = src_tmp[6 * src_stride];
            temp_val4 = src_tmp[7 * src_stride];
        }
        ;
        {
            dst_tmp[12 * dst_stride] = temp_val1;
            dst_tmp[13 * dst_stride] = temp_val2;
            dst_tmp[14 * dst_stride] = temp_val3;
            dst_tmp[15 * dst_stride] = temp_val4;
        }
        ;
        dst_tmp += (4 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
