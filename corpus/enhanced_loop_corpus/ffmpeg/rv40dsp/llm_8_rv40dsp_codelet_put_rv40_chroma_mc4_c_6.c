#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern int i;
extern int bias;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < h; i += 2) {
        dst[0] = (((A * src[0] + E * src[step + 0] + bias)) >> 6);
        dst[1] = (((A * src[1] + E * src[step + 1] + bias)) >> 6);
        dst[2] = (((A * src[2] + E * src[step + 2] + bias)) >> 6);
        dst[3] = (((A * src[3] + E * src[step + 3] + bias)) >> 6);

        if (i + 1 < h) {
            uint8_t *dst_next = dst + stride;
            uint8_t *src_next = src + stride;
            dst_next[0] = (((A * src_next[0] + E * src_next[step + 0] + bias)) >> 6);
            dst_next[1] = (((A * src_next[1] + E * src_next[step + 1] + bias)) >> 6);
            dst_next[2] = (((A * src_next[2] + E * src_next[step + 2] + bias)) >> 6);
            dst_next[3] = (((A * src_next[3] + E * src_next[step + 3] + bias)) >> 6);
        }
        dst += 2 * stride;
        src += 2 * stride;
    }
}
