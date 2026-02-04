#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = height; cnt--;) {
        int offset;
        for (offset = 0; offset < 2; ++offset) {
            dst[offset] = (dst[offset] + src[offset] + 1) >> 1;
        }
        src += stride;
        dst += stride;
    }
}
