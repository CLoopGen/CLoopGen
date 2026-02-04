#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    int temp0 = ((A * src[0] + E * src[step + 0]) + 32) >> 6;
    int temp1 = ((A * src[1] + E * src[step + 1]) + 32) >> 6;
    dst[0] = (dst[0] + temp0 + 1) >> 1;
    dst[1] = (dst[1] + temp1 + 1) >> 1;

    if (i + 1 < h) {
        uint8_t *dst_next = dst + stride;
        uint8_t *src_next = src + stride;
        int temp2 = ((A * src_next[0] + E * src_next[step + 0]) + 32) >> 6;
        int temp3 = ((A * src_next[1] + E * src_next[step + 1]) + 32) >> 6;
        dst_next[0] = (dst_next[0] + temp2 + 1) >> 1;
        dst_next[1] = (dst_next[1] + temp3 + 1) >> 1;
    }

    dst += 2 * stride;
    src += 2 * stride;
}
}
