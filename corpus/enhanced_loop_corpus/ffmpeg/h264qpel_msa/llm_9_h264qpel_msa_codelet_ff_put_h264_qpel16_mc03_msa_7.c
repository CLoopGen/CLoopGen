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
    for (int k = 0; k < 8; ++k) {
        dst[k + 0*stride] = src[k + 0*stride] ^ src[k + 4*stride];
        dst[k + 1*stride] = src[k + 1*stride] ^ src[k + 5*stride];
        dst[k + 2*stride] = src[k + 2*stride] ^ src[k + 6*stride];
        dst[k + 3*stride] = src[k + 3*stride] ^ src[k + 7*stride];
    }
    src += (8 * stride);
    dst += (8 * stride);
}
}
