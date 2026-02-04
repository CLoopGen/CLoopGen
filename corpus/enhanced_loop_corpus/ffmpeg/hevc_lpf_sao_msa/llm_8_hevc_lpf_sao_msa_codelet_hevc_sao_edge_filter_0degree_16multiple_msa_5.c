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
extern uint8_t *dst_ptr;
extern uint8_t *src_minus1;
extern int32_t v_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; height >= 4; height -= 8) {
    src_minus1 = src - 1;
    for (v_cnt = 0; v_cnt < width; v_cnt += 8) {
        src_minus1 += 8;
        dst_ptr = dst + v_cnt;
        {
            uint32_t temp1 = *((uint32_t*)(src_minus1));
            uint32_t temp2 = *((uint32_t*)(src_minus1 + 4));
            uint32_t temp3 = *((uint32_t*)(src_minus1 + src_stride));
            uint32_t temp4 = *((uint32_t*)(src_minus1 + src_stride + 4));
            uint32_t temp5 = *((uint32_t*)(src_minus1 + 2*src_stride));
            uint32_t temp6 = *((uint32_t*)(src_minus1 + 2*src_stride + 4));
            uint32_t temp7 = *((uint32_t*)(src_minus1 + 3*src_stride));
            uint32_t temp8 = *((uint32_t*)(src_minus1 + 3*src_stride + 4));

            temp1 ^= temp3; temp2 ^= temp4;
            temp5 ^= temp7; temp6 ^= temp8;
            temp1 += temp5; temp2 += temp6;
            temp1 &= 0x0F0F0F0F; temp2 &= 0x0F0F0F0F;

            *((uint32_t*)(dst_ptr)) = temp1;
            *((uint32_t*)(dst_ptr + dst_stride)) = temp2;
        }
        {
            uint32_t temp1 = *((uint32_t*)(src_minus1 + 8));
            uint32_t temp2 = *((uint32_t*)(src_minus1 + 12));
            uint32_t temp3 = *((uint32_t*)(src_minus1 + src_stride + 8));
            uint32_t temp4 = *((uint32_t*)(src_minus1 + src_stride + 12));
            uint32_t temp5 = *((uint32_t*)(src_minus1 + 2*src_stride + 8));
            uint32_t temp6 = *((uint32_t*)(src_minus1 + 2*src_stride + 12));
            uint32_t temp7 = *((uint32_t*)(src_minus1 + 3*src_stride + 8));
            uint32_t temp8 = *((uint32_t*)(src_minus1 + 3*src_stride + 12));

            temp1 ^= temp3; temp2 ^= temp4;
            temp5 ^= temp7; temp6 ^= temp8;
            temp1 += temp5; temp2 += temp6;
            temp1 &= 0x0F0F0F0F; temp2 &= 0x0F0F0F0F;

            *((uint32_t*)(dst_ptr + 8)) = temp1;
            *((uint32_t*)(dst_ptr + 8 + dst_stride)) = temp2;
        }
    }
    src += (src_stride << 3);
    dst += (dst_stride << 3);
}
}
