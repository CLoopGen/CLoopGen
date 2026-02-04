#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint16_t prev_dst[8];

for (i = 0; i < h; i++) {
    if (i == 0) {
        prev_dst[0] = dst[0];
        prev_dst[1] = dst[1];
        prev_dst[2] = dst[2];
        prev_dst[3] = dst[3];
        prev_dst[4] = dst[4];
        prev_dst[5] = dst[5];
        prev_dst[6] = dst[6];
        prev_dst[7] = dst[7];
    }

    uint16_t val0 = (((A * src[0] + E * src[step + 0]) + 32) >> 6);
    uint16_t val1 = (((A * src[1] + E * src[step + 1]) + 32) >> 6);
    uint16_t val2 = (((A * src[2] + E * src[step + 2]) + 32) >> 6);
    uint16_t val3 = (((A * src[3] + E * src[step + 3]) + 32) >> 6);
    uint16_t val4 = (((A * src[4] + E * src[step + 4]) + 32) >> 6);
    uint16_t val5 = (((A * src[5] + E * src[step + 5]) + 32) >> 6);
    uint16_t val6 = (((A * src[6] + E * src[step + 6]) + 32) >> 6);
    uint16_t val7 = (((A * src[7] + E * src[step + 7]) + 32) >> 6);

    dst[0] = ((prev_dst[0] + val0 + 1) >> 1);
    dst[1] = ((prev_dst[1] + val1 + 1) >> 1);
    dst[2] = ((prev_dst[2] + val2 + 1) >> 1);
    dst[3] = ((prev_dst[3] + val3 + 1) >> 1);
    dst[4] = ((prev_dst[4] + val4 + 1) >> 1);
    dst[5] = ((prev_dst[5] + val5 + 1) >> 1);
    dst[6] = ((prev_dst[6] + val6 + 1) >> 1);
    dst[7] = ((prev_dst[7] + val7 + 1) >> 1);

    prev_dst[0] = dst[0];
    prev_dst[1] = dst[1];
    prev_dst[2] = dst[2];
    prev_dst[3] = dst[3];
    prev_dst[4] = dst[4];
    prev_dst[5] = dst[5];
    prev_dst[6] = dst[6];
    prev_dst[7] = dst[7];

    dst += stride;
    src += stride;
}
}
