#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 16; i--;) {
    uint8_t temp1, temp2, temp3, temp4;
    temp1 = dst[0];
    temp2 = dst[1];
    temp3 = dst[2];
    temp4 = dst[3];
    
    dst[0] = temp4 + 1;
    dst[1] = temp1 + 1;
    dst[2] = temp2 + 1;
    dst[3] = temp3 + 1;

    {
        temp1 = dst[4];
        temp2 = dst[5];
        dst[4] = temp2 ^ 0xFF;
        dst[5] = temp1 ^ 0xFF;
    }
    
    {
        temp3 ^= temp1;
        temp4 ^= temp2;
        dst[6] = temp3;
        dst[7] = temp4;
    }

    dst += dst_stride;
    dst += dst_stride;
}
}
