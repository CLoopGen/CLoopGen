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
    uint8_t prev_dst[8] = {0}; 
    for (i = 0; i < h; i++) {
        dst[0] = (((A * src[0] + E * src[step + 0] + bias + prev_dst[0]) >> 6));
        dst[1] = (((A * src[1] + E * src[step + 1] + bias + prev_dst[1]) >> 6));
        dst[2] = (((A * src[2] + E * src[step + 2] + bias + prev_dst[2]) >> 6));
        dst[3] = (((A * src[3] + E * src[step + 3] + bias + prev_dst[3]) >> 6));
        dst[4] = (((A * src[4] + E * src[step + 4] + bias + prev_dst[4]) >> 6));
        dst[5] = (((A * src[5] + E * src[step + 5] + bias + prev_dst[5]) >> 6));
        dst[6] = (((A * src[6] + E * src[step + 6] + bias + prev_dst[6]) >> 6));
        dst[7] = (((A * src[7] + E * src[step + 7] + bias + prev_dst[7]) >> 6));

        for (int j = 0; j < 8; j++) {
            prev_dst[j] = dst[j];
        }

        dst += stride;
        src += stride;
    }
}
