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
for (loop_cnt = 4; loop_cnt--;) {
    uint8_t temp1 = src[0];
    uint8_t temp2 = src[stride];
    uint8_t temp3 = src[2*stride];
    uint8_t temp4 = src[3*stride];

    dst[0] = temp1 ^ 0xFF;
    dst[stride] = temp2 ^ 0xFF;
    dst[2*stride] = temp3 ^ 0xFF;
    dst[3*stride] = temp4 ^ 0xFF;

    src += (4 * stride);
    dst += (4 * stride);

    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
}
}
