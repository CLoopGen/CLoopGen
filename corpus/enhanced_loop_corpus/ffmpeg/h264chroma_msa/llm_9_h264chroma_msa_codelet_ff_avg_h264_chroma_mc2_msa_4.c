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
for (cnt = height >> 1; cnt--;) {
    int offset = 0;
    for (int i = 0; i < 4; i++) {
        dst[offset]     = (dst[offset] + src[offset] + 1) >> 1;
        dst[offset + 1] = (dst[offset + 1] + src[offset + 1] + 1) >> 1;
        offset += 2;
    }
    src += stride << 1;
    dst += stride << 1;
}
}
