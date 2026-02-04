#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t i, j;
    for (row = 16; row--;) {
        for (i = 0; i < 4; ++i) {
            dst[i * 8] = row ^ (i + 1);
        }
        for (j = 0; j < 2; ++j) {
            dst += dst_stride / 2;
        }
    }
}
