#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src0_ptr;
extern int32_t src_stride;
extern int16_t *src1_ptr;
extern int32_t src2_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *src0_next;
    int16_t *src1_next;
    uint8_t *dst_next;
    uint8_t *dst_tmp_next;

    for (loop_cnt = (height >> 1); loop_cnt--;) {
        src0_next = src0_ptr + src_stride;
        src1_next = src1_ptr + src2_stride;
        dst_next = dst + dst_stride;
        dst_tmp_next = dst_tmp + dst_stride;

        {
            dst[0] = src0_ptr[0];
            dst[1] = src0_ptr[1];
            dst_next[0] = src0_next[0];
            dst_next[1] = src0_next[1];
        }
        ;
        {
            dst_tmp[0] = src0_ptr[0] ^ 0xFF;
            dst_tmp[1] = src0_ptr[1] ^ 0xFF;
            dst_tmp_next[0] = src0_next[0] ^ 0xFF;
            dst_tmp_next[1] = src0_next[1] ^ 0xFF;
        }
        ;
        {
            ((uint16_t*)dst)[0] += ((int32_t*)src1_ptr)[0];
            ((uint16_t*)dst)[1] += ((int32_t*)src1_ptr)[1];
            ((uint16_t*)dst_next)[0] += ((int32_t*)src1_next)[0];
            ((uint16_t*)dst_next)[1] += ((int32_t*)src1_next)[1];
        }
        ;
        {
            dst[2] = dst[0] + 1;
            dst_next[2] = dst_next[0] + 1;
        }
        ;
        {
            dst_tmp[2] = dst[2] ^ dst_tmp[0];
            dst_tmp_next[2] = dst_next[2] ^ dst_tmp_next[0];
        }
        ;

        dst += (2 * dst_stride);
        src0_ptr += (2 * src_stride);
        src1_ptr += (2 * src2_stride);
        dst_tmp += (2 * dst_stride);
    }
}
