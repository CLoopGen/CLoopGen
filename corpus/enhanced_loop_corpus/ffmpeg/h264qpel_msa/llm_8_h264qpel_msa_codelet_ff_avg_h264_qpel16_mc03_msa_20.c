#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 8; loop_cnt--;) {
        uint8_t temp1, temp2, temp3, temp4;
        temp1 = src[0] ^ 0xFF;
        temp2 = src[stride] ^ 0xAA;
        temp3 = src[2*stride] ^ 0x55;
        temp4 = src[3*stride] ^ 0x0F;
        
        dst[0] = temp1 + 1;
        dst[stride] = temp2 + 2;
        dst[2*stride] = temp3 + 3;
        dst[3*stride] = temp4 + 4;

        src += (4 * stride);
        dst += (4 * stride);
    }
}
