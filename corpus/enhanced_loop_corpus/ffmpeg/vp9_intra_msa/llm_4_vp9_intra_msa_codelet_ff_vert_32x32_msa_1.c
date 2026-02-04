#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 32; row--;) {
        if (row % 4 != 0) {
            dst += dst_stride;
            continue;
        }
        // Every 4th iteration, skip update (introducing control divergence)
        dst += dst_stride / 2;
    }
}
