#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t value_accum = 0;
    for (cnt = (height >> 3); cnt--;) {
        int32_t inner_offset = 0;
        for (int i = 0; i < 8; i++) {
            value_accum ^= src[inner_offset];
            inner_offset += src_stride;
        }
        src += (8 * src_stride);
    }
    // Prevent unused variable warning if needed in larger context
    (void)value_accum;
}
