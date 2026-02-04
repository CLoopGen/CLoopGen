#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 2; loop_cnt--;) {
    for (int sub = 0; sub < 8; sub++) {
        dst[0] = (src[0] + src[1]) >> 1;
        dst[1] = (src[1] + src[2]) >> 1;
        dst[2] = (src[2] + src[3]) >> 1;
        dst[3] = (src[3] + src[0]) >> 1;
        src += stride;
        dst += stride;
    }
    src += (4 * stride); 
    dst += (4 * stride); 
}
}
