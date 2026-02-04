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
    uint8_t prev_dst0 = 0, prev_dst1 = 0;
    for (i = 0; i < h; i++) {
        if (i > 0) {
            dst[0] = ((prev_dst0 + (((A * src[0] + E * src[step + 0]) + 32) >> 6) + 1) >> 1);
            dst[1] = ((prev_dst1 + (((A * src[1] + E * src[step + 1]) + 32) >> 6) + 1) >> 1);
        } else {
            dst[0] = ((dst[0] + (((A * src[0] + E * src[step + 0]) + 32) >> 6) + 1) >> 1);
            dst[1] = ((dst[1] + (((A * src[1] + E * src[step + 1]) + 32) >> 6) + 1) >> 1);
        }
        prev_dst0 = dst[0];
        prev_dst1 = dst[1];
        dst += stride;
        src += stride;
    }
}
