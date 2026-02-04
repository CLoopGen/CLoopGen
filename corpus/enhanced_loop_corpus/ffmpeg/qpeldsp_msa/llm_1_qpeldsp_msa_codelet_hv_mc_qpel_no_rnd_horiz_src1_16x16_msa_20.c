#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (height >= 4) {
        loop_count = height >> 2;
        for (int32_t outer = 0; outer < loop_count; outer++) {
            for (int32_t inner = 0; inner < 4; inner++) {
                {
                    {
                    }
                    ;
                    {
                    }
                    ;
                }
                src += src_stride;
            }
            dst += (4 * dst_stride);
        }
    }
}
