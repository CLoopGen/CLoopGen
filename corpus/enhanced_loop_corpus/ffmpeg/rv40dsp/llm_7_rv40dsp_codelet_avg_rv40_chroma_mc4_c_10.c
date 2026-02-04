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
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    for (i = 0; i < h; i++) {
        int val0 = (A * local_src[0] + E * local_src[step + 0] + bias) >> 6;
        int val1 = (A * local_src[1] + E * local_src[step + 1] + bias) >> 6;
        int val2 = (A * local_src[2] + E * local_src[step + 2] + bias) >> 6;
        int val3 = (A * local_src[3] + E * local_src[step + 3] + bias) >> 6;

        local_dst[0] = ((local_dst[0] + val0 + 1) >> 1);
        local_dst[1] = ((local_dst[1] + val1 + 1) >> 1);
        local_dst[2] = ((local_dst[2] + val2 + 1) >> 1);
        local_dst[3] = ((local_dst[3] + val3 + 1) >> 1);

        local_dst += stride;
        local_src += stride;
    }
}
