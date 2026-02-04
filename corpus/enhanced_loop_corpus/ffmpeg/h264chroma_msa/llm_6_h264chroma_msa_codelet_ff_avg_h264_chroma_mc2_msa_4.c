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
    uint8_t temp0 = (dst[0] + src[0] + 1) >> 1;
    uint8_t temp1 = (dst[1] + src[1] + 1) >> 1;
    dst[0] = temp0;
    dst[1] = temp1;
    src += stride;
    dst += stride;
}
}
