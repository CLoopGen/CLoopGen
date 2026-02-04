#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 2; loop_cnt--;) {
    src += (8 * stride);
    {
        dst += (16 * stride);
    }
    ;
    {
        for (uint32_t j = 0; j < 4; ++j) {
            dst += (2 * stride);
        }
    }
    ;
    {
        src += (4 * stride);
    }
    ;
    {
        dst += (8 * stride);
    }
    ;
    for (uint32_t k = 0; k < 3; ++k) {
        {
            dst += stride;
        }
        ;
        {
            src += stride;
        }
    }
}
}
