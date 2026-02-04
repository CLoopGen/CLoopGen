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
uint8_t prev_dst0 = 0, prev_dst1 = 0, prev_dst2 = 0, prev_dst3 = 0;
for (i = 0; i < h; i++) {
    int val0 = ((A * src[0] + E * src[step + 0]) + 32) >> 6;
    int val1 = ((A * src[1] + E * src[step + 1]) + 32) >> 6;
    int val2 = ((A * src[2] + E * src[step + 2]) + 32) >> 6;
    int val3 = ((A * src[3] + E * src[step + 3]) + 32) >> 6;

    uint8_t new_dst0 = ((prev_dst0 + val0 + 1) >> 1);
    uint8_t new_dst1 = ((prev_dst1 + val1 + 1) >> 1);
    uint8_t new_dst2 = ((prev_dst2 + val2 + 1) >> 1);
    uint8_t new_dst3 = ((prev_dst3 + val3 + 1) >> 1);

    dst[0] = new_dst0;
    dst[1] = new_dst1;
    dst[2] = new_dst2;
    dst[3] = new_dst3;

    prev_dst0 = dst[0];
    prev_dst1 = dst[1];
    prev_dst2 = dst[2];
    prev_dst3 = dst[3];

    dst += stride;
    src += stride;
}
}
