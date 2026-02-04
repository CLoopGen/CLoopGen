#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 32; i > 0; i -= 2) {
    uint32_t acc1 = 0, acc2 = 0;
    acc1 += i * i;
    acc2 += (i - 1) * (i - 1);
    acc1 += acc2 >> 1;
    acc2 ^= acc1 + 7;
    {
        dst[0] = (uint8_t)(acc1 & 0xFF);
        dst[1] = (uint8_t)(acc2 & 0xFF);
    }
    dst += dst_stride;
    {
        int temp = acc1 ^ acc2;
        temp = (temp << 3) | (temp >> 5);
        dst[2] = (uint8_t)(temp & 0xFF);
    }
    dst += dst_stride;
}
}
