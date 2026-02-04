#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            int weight_src1 = y;
            int weight_src2 = 8 - y;
            if (x >= 4)
                weight_src1 = (y + 1);
            dst[x] = (src[15 - y] * weight_src1 + src[17 + x] * weight_src2 + 4) >> 3;
        }
        dst += stride;
    }
}
