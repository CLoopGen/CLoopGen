#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 1); loop_cnt--;) {
    src += src_stride;
    uint8_t temp1 = src[0];
    uint8_t temp2 = src[src_stride];
    uint8_t temp3 = src[2 * src_stride];
    uint8_t temp4 = src[3 * src_stride];
    
    dst[0] = temp1 ^ temp2;
    dst[src_stride] = temp3 ^ temp4;
    
    {
        dst[2] = temp1 + temp3;
        dst[3] = temp2 + temp4;
    }
    ;
    {
        dst[4] ^= temp1;
        dst[5] ^= temp2;
        {
            dst[6] = temp3 - temp1;
            dst[7] = temp4 - temp2;
        }
        ;
        {
            temp1 = dst[4] & 0x0F;
            temp2 = dst[5] & 0xF0;
        }
        ;
        {
            dst[8] = temp1 | temp2;
        }
        ;
    }
    ;
    src += src_stride;
    dst += dst_stride;
    
    {
        uint8_t next_temp = src[1];
        dst[1] = next_temp + temp1;
    }
    ;
    {
        dst[9] = temp2 ^ src[2];
        dst[10] = temp3 ^ src[3];
    }
    ;
    dst += dst_stride;
}
}
