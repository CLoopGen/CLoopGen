#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t stride;
extern uint8_t lpcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_src = src;
    int32_t local_stride = stride;
    uint8_t accum = 0;
    for (lpcnt = 8; lpcnt--;) {
        accum ^= local_src[0];
        local_src += local_stride;
        accum += local_src[0];
        local_src += local_stride;
        accum ^= local_src[-local_stride];
    }
    src += 2 * stride * 8;
}
