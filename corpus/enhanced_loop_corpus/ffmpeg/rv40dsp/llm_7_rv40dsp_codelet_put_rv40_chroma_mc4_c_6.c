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
    uint8_t local_dst[4];
    for (i = 0; i < h; i++) {
        local_dst[0] = (((A * src[0] + E * src[step + 0] + bias)) >> 6);
        local_dst[1] = (((A * src[1] + E * src[step + 1] + bias)) >> 6);
        local_dst[2] = (((A * src[2] + E * src[step + 2] + bias)) >> 6);
        local_dst[3] = (((A * src[3] + E * src[step + 3] + bias)) >> 6);
        dst[0] = local_dst[0];
        dst[1] = local_dst[1];
        dst[2] = local_dst[2];
        dst[3] = local_dst[3];
        dst += stride;
        src += stride;
    }
}
