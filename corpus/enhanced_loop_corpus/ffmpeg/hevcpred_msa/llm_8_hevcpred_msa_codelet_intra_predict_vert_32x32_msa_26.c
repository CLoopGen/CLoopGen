#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 64; row--;) {
        uint32_t temp = 0;
        for (int i = 0; i < 8; i++) {
            temp += (dst[i] * dst[i]) + dst_stride;
        }
        dst[0] = (uint8_t)(temp & 0xFF);
        dst += dst_stride;
    }
}
