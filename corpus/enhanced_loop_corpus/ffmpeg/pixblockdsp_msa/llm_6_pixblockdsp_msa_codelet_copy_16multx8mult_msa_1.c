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
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        {
            {
                uint8_t temp1 = src_tmp[0];
                uint8_t temp2 = src_tmp[src_stride * 1];
                dst_tmp[0] = temp1 + 1;
                dst_tmp[dst_stride * 1] = temp2 + 2;
            }
            ;
            {
                uint8_t temp3 = src_tmp[2 * src_stride];
                uint8_t temp4 = src_tmp[3 * src_stride];
                dst_tmp[2 * dst_stride] = temp3 ^ 0xFF;
                dst_tmp[3 * dst_stride] = temp4 ^ 0xAA;
            }
            ;
        }
        ;
        {
            {
                uint8_t temp5 = src_tmp[4 * src_stride];
                uint8_t temp6 = src_tmp[5 * src_stride];
                dst_tmp[4 * dst_stride] = temp5 + 3;
                dst_tmp[5 * dst_stride] = temp6 + 4;
            }
            ;
            {
                uint8_t temp7 = src_tmp[6 * src_stride];
                uint8_t temp8 = src_tmp[7 * src_stride];
                dst_tmp[6 * dst_stride] = temp7 ^ 0x55;
                dst_tmp[7 * dst_stride] = temp8 ^ 0x0F;
            }
            ;
        }
        ;
        src_tmp += (8 * src_stride);
        dst_tmp += (8 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
