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
    if (i + 1 < h) {
        dst[0] = ((((A * src[0] + E * src[step + 0])) + 32) >> 6);
        dst[1] = ((((A * src[1] + E * src[step + 1])) + 32) >> 6);
        dst[2] = ((((A * src[2] + E * src[step + 2])) + 32) >> 6);
        dst[3] = ((((A * src[3] + E * src[step + 3])) + 32) >> 6);
        dst[4] = ((((A * src[4] + E * src[step + 4])) + 32) >> 6);
        dst[5] = ((((A * src[5] + E * src[step + 5])) + 32) >> 6);
        dst[6] = ((((A * src[6] + E * src[step + 6])) + 32) >> 6);
        dst[7] = ((((A * src[7] + E * src[step + 7])) + 32) >> 6);

        uint8_t *dst_next = dst + stride;
        uint8_t *src_next = src + stride;

        dst_next[0] = ((((A * src_next[0] + E * src_next[step + 0])) + 32) >> 6);
        dst_next[1] = ((((A * src_next[1] + E * src_next[step + 1])) + 32) >> 6);
        dst_next[2] = ((((A * src_next[2] + E * src_next[step + 2])) + 32) >> 6);
        dst_next[3] = ((((A * src_next[3] + E * src_next[step + 3])) + 32) >> 6);
        dst_next[4] = ((((A * src_next[4] + E * src_next[step + 4])) + 32) >> 6);
        dst_next[5] = ((((A * src_next[5] + E * src_next[step + 5])) + 32) >> 6);
        dst_next[6] = ((((A * src_next[6] + E * src_next[step + 6])) + 32) >> 6);
        dst_next[7] = ((((A * src_next[7] + E * src_next[step + 7])) + 32) >> 6);

        dst += 2 * stride;
        src += 2 * stride;
    } else {
        dst[0] = ((((A * src[0] + E * src[step + 0])) + 32) >> 6);
        dst[1] = ((((A * src[1] + E * src[step + 1])) + 32) >> 6);
        dst[2] = ((((A * src[2] + E * src[step + 2])) + 32) >> 6);
        dst[3] = ((((A * src[3] + E * src[step + 3])) + 32) >> 6);
        dst[4] = ((((A * src[4] + E * src[step + 4])) + 32) >> 6);
        dst[5] = ((((A * src[5] + E * src[step + 5])) + 32) >> 6);
        dst[6] = ((((A * src[6] + E * src[step + 6])) + 32) >> 6);
        dst[7] = ((((A * src[7] + E * src[step + 7])) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
}
